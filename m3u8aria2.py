from requests import get, post
from urllib import parse
import os
import shutil
import re
import tempfile
from xmlrpc.client import ServerProxy
import socket
from contextlib import closing
from subprocess import Popen, PIPE
import time


def find_free_port():
    with closing(socket.socket(socket.AF_INET, socket.SOCK_STREAM)) as s:
        s.bind(('', 0))
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        return s.getsockname()[1]


class M3U8aria2:
    def __init__(self, dir="D:/", limit="0"):
        self.dir = dir
        self.port = find_free_port()
        cmd = "aria2c.exe --conf=aria2.conf --rpc-listen-port=%d --max-overall-download-limit=%s --max-concurrent-downloads=20 --max-connection-per-server=16" % (
            self.port, limit)
        cmd = cmd.split()
        cmd.append("--user-agent=\"Mozilla/5.0 (Windows NT 10.0; WOW64; rv:42.0) Gecko/20100101 Firefox/42.0\"")
        self.process = Popen(cmd, stdout=None, stderr=None)

    def close(self):
        self.process.kill()

    def download(self, url, series, episode, headers={}):
        c = ServerProxy('http://localhost:%d/rpc' % self.port)
        p = parse.urlparse(url)
        r = get(url, headers=headers)
        outdir = self.dir + "/%s/" % series
        tempdir = tempfile.mkdtemp()
        found = True
        while found:
            found = False
            for line in r.text.splitlines():
                if line.endswith("m3u8"):
                    found = True
                    if (line.startswith("/")):
                        url = "%s://%s%s" % (p.scheme, p.netloc, line)
                    elif (line.startswith("http")):
                        url = line
                    else:
                        url = "/".join(url.split("/")[0:-1]) + "/" + line
                    p = parse.urlparse(url)
                    r = get(url, headers=headers)
        m3u8url = url
        m3u8p = p
        count = 0
        outm3u8 = ""
        for i in r.text.splitlines():
            if (not i.startswith("#")):
                url = ""
                if (i.startswith("/")):
                    url = "%s://%s%s" % (m3u8p.scheme, m3u8p.netloc, i)
                elif (i.startswith("http")):
                    url = i
                else:
                    url = "/".join(m3u8url.split("/")[0:-1]) + "/" + i
                opts = dict(
                    out="%d.ts" % count,
                    dir=tempdir,
                    header=["Origin: https://chinaq.tv",
                            "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36"],
                )
                print(url)
                c.aria2.addUri([url], opts)
                outm3u8 += "%d.ts\r\n" % count
                count += 1
            else:
                if (i.startswith("#EXT-X-KEY")):
                    x = re.search("^.+URI=\"(.+)\"$", i)
                    if x:
                        opts = dict(
                            out="key.key",
                            dir=tempdir,
                            header=["Origin: https://chinaq.tv",
                                    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36"],
                        )
                        url = x[1]
                        if url.startswith("http"):
                            pass
                        else:
                            url = "%s://%s%s" % (m3u8p.scheme, m3u8p.netloc, url)
                        print(url)
                        c.aria2.addUri([url], opts)
                        outm3u8 += i.replace(x[1], "key.key")+"\r\n"
                else:
                    outm3u8 += i+"\r\n"
        with open(tempdir+"/index.m3u8", "w") as f:
            f.write(outm3u8)
            f.close()
        r = c.aria2.getGlobalStat()
        while int(r["numActive"]) > 0 or int(r["numWaiting"]) > 0:
            # print("waiting %05d %05d\r" %
            #       (int(r["numActive"]), int(r["numWaiting"])), end="\r")
            r = c.aria2.getGlobalStat()
            time.sleep(0.1)
        print("downloaded")
        os.makedirs(outdir, exist_ok=True)
        os.system("ffmpeg -allowed_extensions ALL -i \"%s\" -c copy \"%s\"" %
                  (tempdir+"/index.m3u8", "%s/%s.mp4" % (outdir, episode)))
        shutil.rmtree(tempdir)
