public class Test {
   public static void main(String[] args) {

      dataset ds = new dataset();

      ds.add(new audio_entry("audio1",30));
      ds.add(new audio_entry("audio2",60));

      ds.add(new image_entry("image1",256));
      ds.add(new image_entry("image2",512));

      ds.add(new text_entry("text1"));
      ds.add(new text_entry("text2"));

      ds.add(new video_entry("video1",256,360));
      ds.add(new video_entry("video2",512,720));

      ds.add(new audio_entry("audio3",40));
      ds.add(new audio_entry("audio4",80));

      player p1 = new player();
      player p2 = new player();
      viewer v1 = new viewer();

      ds.register(p1);
      ds.register(p2);
      ds.register(v1);

      v1.show_list(); // show non-playable object list in dataset
      System.out.println("---------------------Test1");

      p1.show_list(); // show playble object list in dataset
      System.out.println("---------------------Test2");

      // Current-playing object -> audio1
      p1.next("Video");
      // Current-playing object -> video1
      p1.next("Audio");
      // Current-playing object -> audio3
      p1.show_list(); // next function usability
      System.out.println("---------------------Test3");

      // Current-playing object -> 1
      p2.previous("Audio"); // audio1 is first object. print error message
      System.out.println("---------------------Test4");

      ds.type_list();// all object type list
      System.out.println("---------------------Test5");

      ds.show_list();// all object info list
      System.out.println("---------------------Test6");

      ds.remove_observer(p2);
      p2.show_list();// print error message -

      System.out.println("---------------------Test7");

      ds.add(new audio_entry("audio5"));
      ds.add(new audio_entry("audio6"));
      // update observers
      p1.show_list();
      System.out.println("---------------------Test8");

      ds.remove("audio1");
      // Current-playing object -> audio3
      p1.show_list();
      System.out.println("---------------------Test9");

      ds.remove("audio3");
      // Current-playing object -> audio4
      p1.show_list();
      System.out.println("---------------------Test10");

      ds.remove("ys");// nothing removed
      p1.show_list();
      System.out.println("---------------------Test11");

      p1.next("Video");// Print error message. no video avaible for next
      System.out.println("---------------------Test12");

      // Current-playing object -> audio4
      p1.previous();// plays previous object, type is not important
      // Current-playing object -> video2
      p1.previous("Audio");
      // Current-playing object -> audio2 (first item)
      p1.show_list();
      System.out.println("---------------------Test13");


      v1.next("Text");
      non_playable np = v1.currently_viewing();
      np.info();

      ds.remove(np);//remove text1 in dataset

      System.out.println("");
      System.out.println("");

      v1.show_list();// Current viewing object -> text2
      
      System.out.println("---------------------Test14");

      v1.remove("image1");
      v1.remove("image2");
      v1.remove("text2");
      //now v1 is empty
      System.out.println("---------------------Test15");

      ds.add(new text_entry("text3"));//update v1 
      v1.show_list();// viewing object -> text3
      System.out.println("---------------------Test16");

   }
}