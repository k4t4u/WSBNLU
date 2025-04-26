package parametry;

import java.util.ArrayList;
import java.util.List;

public class Zbior<T> {
    private List<T> lista;

    public Zbior() {
        this.lista = new ArrayList<>();
    }

    public List<T> getLista() {
        return lista;
    }

    public void dodaj(T element) {
        lista.add(element);
    }

    public void wyswietlWszystkie() {
        for (T elemement : lista) {
            System.out.println(elemement.toString());
        }
    }
}
