import java.util.ArrayList;
import java.util.List;

public class dataset {

    private List<entry> entryy = new ArrayList<>();
    private List<observer> observers = new ArrayList<>();

    public void add(entry entry) {  // update observers

        entryy.add(entry);

        for (int i = 0; i < observers.size(); ++i) {

            if (observers.get(i) instanceof player) {

                if (entry instanceof playable) {

                    observers.get(i).update(entry);
                }
            } else if (observers.get(i) instanceof viewer) {

                if (entry instanceof non_playable) {

                    observers.get(i).update(entry);
                }
            }
        }

    }

    public void register(observer current) { // register observer class

        observers.add(current);
        int size;
        size = observers.size() - 1;
        if (current instanceof player) {
            for (int i = 0; i < entryy.size(); ++i) {

                if (entryy.get(i) instanceof playable) {

                    observers.get(size).update(entryy.get(i));
                }
            }
        }
        if (current instanceof viewer) {

            for (int i = 0; i < entryy.size(); ++i) {

                if (entryy.get(i) instanceof non_playable) {

                    observers.get(size).update(entryy.get(i));
                }
            }
        }
        observers.get(size).register();

    }

    public void remove_observer(observer x) { // delete observer class

        for (int i = 0; i < observers.size(); ++i) {

            if (observers.get(i) == x) {

                observers.get(i).remove_observer();
                observers.remove(i);
            }
        }
    }

    public void remove(non_playable x){ // remove current viewing non-playable item


        remove(x.getName());
    }

    public void remove(playable x){ // remove current playing playable item

        remove(x.getName());
    }

    public void remove(String name) { // delete item knowing name 

        for (int i = 0; i < entryy.size(); ++i) {

            if (name == entryy.get(i).get_name()) {

                entryy.remove(i);
                for (int j = 0; j < observers.size(); ++j) {

                    observers.get(j).remove(name);

                }

                return;
            }
        }
    }

    public void type_list() { // print arraylist entryy type list

        for (int i = 0; i < entryy.size(); ++i) {

            System.out.println(entryy.get(i).get_type());
        }
    }

    public void show_list() {// print arraylist entryy info list

        for (int i = 0; i < entryy.size(); ++i) {

            entryy.get(i).info();
        }
    }
}
