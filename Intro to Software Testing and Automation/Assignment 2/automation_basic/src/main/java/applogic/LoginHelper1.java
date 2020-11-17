package applogic;

import models.User;
import pages.super_pages.InternalPage;
import pages.util_pages.LoginPage;

public class LoginHelper1 extends DriverBasedHelper {

	public LoginHelper1(ApplicationManager1 manager) {
		super(manager);
	}


	public InternalPage loginAs(User user) {
		pages.loginPage.ensurePageLoaded().setUsernameField(user.getUsername()).setPasswordField(user.getPassword())
				.clickSubmit();

		return pages.internalPage.ensurePageLoaded();

	}
	public InternalPage loginAs(String login, String password) {
		pages.loginPage.ensurePageLoaded().setUsernameField(login).setPasswordField(password).clickSubmit();

		return pages.internalPage.ensurePageLoaded();

	}

	public LoginPage logout() {
		return pages.internalPage.logout();
	}

}
