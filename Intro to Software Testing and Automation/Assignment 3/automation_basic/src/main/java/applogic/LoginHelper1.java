package applogic;

import pages.util_pages.HomePage;

public class LoginHelper1 extends DriverBasedHelper {

	public LoginHelper1(ApplicationManager1 manager) {
		super(manager);
	}


	public HomePage logout() {
		return pages.menusPage.logout();
	}

}
