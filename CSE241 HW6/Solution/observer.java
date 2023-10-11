public interface observer {

    public void info();
    public void update(entry New);
    public void add(entry New);
    public void register();
    public void remove(String name);
    public void remove_observer();
}
