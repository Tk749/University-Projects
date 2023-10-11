public class text_entry extends entry implements non_playable, non_visual {

    public text_entry(String name) {

        super(name);
    }

    public text_entry() {

        super("");
    }

    public void info() {

        System.out.println("Type: "+get_type());
        System.out.println("    Name: " + this.get_name());
    }

    public void playing_info() {

        System.out.println("Type : "+get_type() + "   -> Current playing");
        System.out.println("    Name: " + this.get_name());
    }

    public String get_type() {

        return "Text";
    }
    public String getName(){

        return get_name();
    }
}
