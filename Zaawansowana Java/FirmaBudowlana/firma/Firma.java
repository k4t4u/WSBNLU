package firma;

import bazyDanych.BazaDanych;

public class Firma {
    private String nazwa;
    private BazaDanych bazaDanych;

    public Firma(String nazwa) {
        this.nazwa = nazwa;
        this.bazaDanych = new BazaDanych();
    }

    public String getNazwa() {
        return nazwa;
    }

    public BazaDanych getBazaDanych() {
        return bazaDanych;
    }
}
