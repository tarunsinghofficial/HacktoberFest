tujuan = "BOGOR - JAKARTA"
uangDiDompet = 10000

ticket = {'BOGOR - JAKARTA':8000,'BOGOR - BANDUNG':9000,'BOGOR - GARUT':6000,'BOGOR - SUBANG':4000}

if tujuan in ticket:
  if uangDiDompet >= ticket[tujuan]:
    print('okay ticket telah terbeli silahkan bersenang senang ~')
    uangDiDompet -= ticket[tujuan]
  else :
    print('uang anda tidak cukup untuk membeli tiket tujuan {}'.format(tujuan))
else :
  print('maaf ticket untuk tujuan anda sedang kosong')

print("Sisa uang anda adalah {}".format(uangDiDompet))