import java.util.ArrayList;
import java.util.List;

public class player implements observer {

    private List<playable> playableEntry = new ArrayList<>();
    private int currentPlayingİndex = -1;

    public void register() {// register dataset

        if (playableEntry.size() == 0)
            currentPlayingİndex = 0;
    }

    public void update(entry New) { // update playble arraylist
        if (currentPlayingİndex == -1) {

            currentPlayingİndex = 0;
        }
        add(New);
    }

    public void add(entry New) { // add new item in playable arraylist
        playable temp = (playable) New;
        playableEntry.add(temp);
    }

    public void remove_observer() {// remove in dataset

        playableEntry.clear();
        currentPlayingİndex = -1;
    }

    public void remove(String name) { // delete item knowing name

        for (int i = 0; i < playableEntry.size(); ++i) {

            if (name == playableEntry.get(i).getName()) {
                playableEntry.remove(i);

                if (playableEntry.size() == 0) {

                    System.out.println("Player is empty. Nothing playing");
                    return;
                }

                if (currentPlayingİndex == playableEntry.size()) {

                    currentPlayingİndex = currentPlayingİndex - 1;
                    System.out.println("Error! The last item is removed, the previous item is playing");
                    return;
                }
                if (currentPlayingİndex > i) {

                    currentPlayingİndex += -1;
                    return;
                }
            }
        }
    }

    public void next() { // next item

        if (currentPlayingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentPlayingİndex == playableEntry.size() - 1) {

            System.out.println("Error! Next item not found");
            return;

        }

        currentPlayingİndex += 1;

    }

    public void next(String s) { // next item knowing type

        if (currentPlayingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (s == "Audio") {

            for (int i = currentPlayingİndex + 1; i < playableEntry.size(); ++i) {

                if (playableEntry.get(i) instanceof audio_entry) {

                    currentPlayingİndex = i;
                    return;
                }
            }
        }

        if (s == "Video") {

            for (int i = currentPlayingİndex + 1; i < playableEntry.size(); ++i) {

                if (playableEntry.get(i) instanceof video_entry) {

                    currentPlayingİndex = i;
                    return;
                }
            }
        }
        System.out.println("Error! Next item not found");
    }

    public void previous(String s) { // previous item knowing name

        if (currentPlayingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentPlayingİndex != 0) {

            if (s == "Audio") {

                for (int i = currentPlayingİndex - 1; i < playableEntry.size(); --i) {

                    if (playableEntry.get(i) instanceof audio_entry) {

                        currentPlayingİndex = i;
                        return;
                    }
                }
            }

            if (s == "Video") {

                for (int i = currentPlayingİndex - 1; i >= 0; --i) {

                    if (playableEntry.get(i) instanceof video_entry) {

                        currentPlayingİndex = i;
                        return;
                    }
                }
            }

        } else {

            System.out.println("Error! First item");
        }
    }

    public void previous() { // previous item

        if (currentPlayingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        if (currentPlayingİndex != 0) {

            currentPlayingİndex = currentPlayingİndex - 1;
        } else {

            System.out.println("Error! First item");
        }
    }

    public void show_list() {

        if (currentPlayingİndex == -1) {

            System.out.println("Error! This observer is empty");
            return;
        }

        for (int i = 0; i < playableEntry.size(); ++i) {

            if (playableEntry.get(i) != playableEntry.get(currentPlayingİndex)) {

                playableEntry.get(i).info();
            } else {
                playableEntry.get(i).playing_info();
            }
        }
    }

    public void info() {

        playableEntry.get(currentPlayingİndex).playing_info();
    }

    public playable currently_playing() {

        return playableEntry.get(currentPlayingİndex);
    }

}