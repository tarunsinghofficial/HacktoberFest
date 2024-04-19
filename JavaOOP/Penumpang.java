package angga.relasiclass.percobaan4;

public class Penumpang {
    private String ktp;
    private String nama;

    Penumpang(String ktp, String nama){
        this.ktp = ktp;
        this.nama = nama;
    }
    public void setKtp(String ktp) {
        this.ktp = ktp;
    }
    public String getKtp(){
        return ktp;
    }
    public void setNama(String nama) {
        this.nama = nama;
    }
    public String getNama(){
        return nama;
    }
    public String info() {
        String info = "";
        info += "Ktp: " + ktp + "\n";
        info += "Nama: " + nama + "\n";
        return info;
    }
}
