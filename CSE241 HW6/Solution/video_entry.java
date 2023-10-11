
public class video_entry extends entry implements visual, playable {
    
    private int Dimension = 0;
    private int Duration = 0;
    public video_entry(String name) {

        super(name);
    }
    
    public video_entry(String name, int dimension,int duration){
        super(name);
        Dimension = dimension;
        Duration = duration;
    }

    public video_entry() {

        super("");
    }
    public int get_dimension(){

        return Dimension;
    }
    public int get_duration(){

        return Duration;
    }
    public void info() {

        System.out.println("Type: "+get_type());
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Dimension : " + get_dimension());
        System.out.println("    Duration : "+ get_duration());

    }

    public void playing_info() {

        System.out.println("Type : "+get_type() + "   -> Current playing");
        System.out.println("    Name: " + this.get_name());
        System.out.println("    Duration : "+ get_dimension());
        System.out.println("    Duration : "+ get_duration());


    }

    public String get_type() {

        return "Video";
    }

    public String getName(){

        return get_name();
    }

}
