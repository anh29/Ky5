package model.bean;

public class Wife {
	private String nameString;
	private String addressString;
	private boolean alive;
	
	public String getName() {
		return nameString;
	}
	
	public void setName(String nameString) {
		this.nameString = nameString;
	}

	public String getAddress() {
		return addressString;
	}
	
	public void setAddress(String addressString) {
		this.addressString = addressString;
	}
	
	public boolean isAlive() {
		return alive;
	}
	
	public void setAlive(boolean alive) {
		this.alive = alive;
	}
}
