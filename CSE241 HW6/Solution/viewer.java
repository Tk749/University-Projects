import java.util.ArrayList;
import java.util.List;

public class viewer implements observer {

    private List<non_playable> nonplayableEntry = new ArrayList<>();
    private int currentViewingİndex = -1;

    public void register() {// register dataset

        if (nonplayableEntry.size() == 0)
            currentViewingİndex = 0;
    }

    public void update(entry New) {// update playble arraylist

        if (currentViewingİndex == -1) {

            currentViewingİndex = 0;
        }
        add(New);
    }

    public void add(entry New) { // add new item in playable arraylist
        non_playable temp = (non_playable) New;
        nonplayableEntry.add(temp);
    }

    public void remove_observer() {// remove in dataset

        nonplayableEntry.clear();
        currentViewingİndex = -1;
    }

    public void remove(String name) {// delete item knowing name

        for (int i = 0; i < nonplayableEntry.size(); ++i) {

            if (name == nonplayableEntry.get(i).getName()) {
                nonplayableEntry.remove(i);

                if (nonplayableEntry.size() == 0) {

                    System.out.println("Viewer is empty. Nothing viewing");
                    return;
                }

                if (currentViewingİndex == nonplayableEntry.size()) {

                    currentViewingİndex = currentViewingİndex - 1;
                    System.out.println("Error! The last item is removed, the previous item is viewing");
                    return;
                }
                if (currentViewingİndex > i) {

                    currentViewingİndex += -1;
                    return;
                }
            }
        }
    }

    public void next() {// next item

        if (currentViewingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentViewingİndex == nonplayableEntry.size() - 1) {

            System.out.println("Error! Next item not found");
            return;

        }

        currentViewingİndex += 1;

    }

    public void next(String s) {// next item knowing type

        if (currentViewingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (s == "Image") {

            for (int i = currentViewingİndex + 1; i < nonplayableEntry.size(); ++i) {

                if (nonplayableEntry.get(i) instanceof image_entry) {

                    currentViewingİndex = i;
                    return;
                }
            }
        }

        if (s == "Text") {

            for (int i = currentViewingİndex + 1; i < nonplayableEntry.size(); ++i) {

                if (nonplayableEntry.get(i) instanceof text_entry) {

                    currentViewingİndex = i;
                    return;
                }
            }
        }
        System.out.println("Error! Next item not found");

    }

    public void previous(String s) {// previous item knowing name

        if (currentViewingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentViewingİndex != 0) {

            if (s == "Image") {

                for (int i = currentViewingİndex - 1; i < nonplayableEntry.size(); --i) {

                    if (nonplayableEntry.get(i) instanceof image_entry) {

                        currentViewingİndex = i;
                        return;
                    }
                }
            }

            if (s == "Text") {

                for (int i = currentViewingİndex - 1; i >= 0; --i) {

                    if (nonplayableEntry.get(i) instanceof text_entry) {

                        currentViewingİndex = i;
                        return;
                    }
                }
            }

        } else {

            System.out.println("Error! First item");
        }
    }

    public void previous() {// previous item

        if (currentViewingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentViewingİndex != 0) {

            currentViewingİndex = currentViewingİndex - 1;
        } else {

            System.out.println("Error! First item");
        }
    }

    public void show_list() {

        if (currentViewingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        for (int i = 0; i < nonplayableEntry.size(); ++i) {

            if (nonplayableEntry.get(i) != nonplayableEntry.get(currentViewingİndex)) {

                nonplayableEntry.get(i).info();
            } else {
                nonplayableEntry.get(i).playing_info();
            }
        }
    }

    public void info() {

        nonplayableEntry.get(currentViewingİndex).playing_info();
    }

    public non_playable currently_viewing() {

        return nonplayableEntry.get(currentViewingİndex);
    }

}