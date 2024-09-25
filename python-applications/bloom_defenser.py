import math
import hashlib
import sys

class BloomFilter:
    def __init__(self, capacity, error_rate=0.01):
        self.capacity = capacity
        self.error_rate = error_rate
        self.size = self._best_m(capacity, error_rate)
        self.num_hashes = self._best_k(capacity, error_rate)
        self.bit_array = [0] * self.size

    def add(self, item):
        hashes = self._get_hashes(item)
        for h in hashes:
            self.bit_array[h] = 1

    def contains(self, item):
        hashes = self._get_hashes(item)
        return all(self.bit_array[h] for h in hashes)

    def _get_hashes(self, item):
        item = item.encode('utf-8')
        hash1 = int(hashlib.md5(item).hexdigest(), 16)
        hash2 = int(hashlib.sha256(item).hexdigest(), 16)
        return [(hash1 + i * hash2) % self.size for i in range(self.num_hashes)]

    @staticmethod
    def _best_m(capacity, error_rate):
        return math.ceil(-capacity * math.log(error_rate) / (math.log(2) ** 2))

    @staticmethod
    def _best_k(capacity, error_rate):
        return math.ceil((math.log(2) * BloomFilter._best_m(capacity, error_rate)) / capacity)


BLOCKED_IPS = [
    "192.168.0.1",
    "203.0.113.45",
    "198.51.100.23",
    "203.0.113.13",
    "192.168.0.254"
]

def check_ip(ip):
    capacity = 100  
    bloom = BloomFilter(capacity)
    
    for blocked_ip in BLOCKED_IPS:
        bloom.add(blocked_ip)

    if bloom.contains(ip):
        print(f"ALERT: The IP {ip} has been identified as a blocked IP.")
    else:
        print(f"The IP {ip} is clean.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python bloom_defenser.py <IP>")
        sys.exit(1)

    ip_to_check = sys.argv[1]
    check_ip(ip_to_check)
