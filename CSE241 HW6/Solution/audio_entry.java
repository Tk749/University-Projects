public class audio_entry extends entry implements playable, non_visual {

    private int Duration = 0;

    public audio_entry(String name) {

        super(name);
    }

    public String getName(){

        return get_name();
    }

    public audio_entry(String name, int duration){

        super(name);
        Duration = duration;
    }
    
    public audio_entry() {

        super("");
    }

    public int get_duration(){

        return Duration;
    }

    public void info() {

        System.out.println("Type: " +get_type());
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Duration : " + get_duration());
    }

    public void playing_info() {

        System.out.println("Type : " + get_type() + "   -> Current playing");
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Duration : "+ get_duration());

    }

    public String get_type() {

        return "Audio";
    }

}
