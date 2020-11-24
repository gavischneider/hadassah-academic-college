package pages.util_pages;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class LoginPage extends MenusPage {

	public LoginPage(MainPageManager pages) {
		super(pages);
	}

	public LoginPage ensurePageLoaded() {
		super.ensurePageLoaded();
		waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.cssSelector(".login-button"))));
		return this;
	}

	public LoginPage setEmail(String email) {
		log.info("Set email " + email);
		driver.findElement(By.id("Email")).sendKeys(email);
		return this;
	}

	public LoginPage setPassword(String password) {
		log.info("Set password " + password);
		driver.findElement(By.id("Password")).sendKeys(password);
		return this;
	}

	public HomePage clickLoginButton() {
		driver.findElement(By.cssSelector(".login-button")).click();
		return pages.homePage.ensurePageLoaded();
	}

}
