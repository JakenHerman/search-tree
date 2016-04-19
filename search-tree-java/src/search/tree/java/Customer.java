package search.tree.java;

/**
 *
 * @author jaken herman
 */
public class Customer extends KeyedItem<String> {
    
    private String name;
    private String phoneNumber;

    public Customer(String key, String name, String phone) {
        super(key); //sets the key value to String key
        this.name = name;
        phoneNumber = phone;
    } // end constructor
    
    public String toString() {
        return getKey() + " # " + name;
    } //end toString
    
} // end Customer
