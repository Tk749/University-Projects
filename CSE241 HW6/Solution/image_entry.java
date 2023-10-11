public class image_entry extends entry implements non_playable, visual {

    private int Dimension = 0;
    public image_entry(String name) {

        super(name);
    }
    
    public image_entry(String name, int dimension){
        super(name);
        Dimension = dimension;
    }

    public image_entry() {

        super("");
    }
    public int get_dimension(){

        return Dimension;
    }
    public void info() {

        System.out.println("Type: "+get_type());
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Dimension : " + get_dimension());
    }

    public void playing_info() {

        System.out.println("Type : "+get_type() + "   -> Current playing");
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Duration : "+ get_dimension());

    }

    public String get_type() {

        return "İmage";
    }
    public String getName(){

        return get_name();
    }
}
