package pages.super_pages;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.util_pages.HomePage;
import pages.util_pages.LoginPage;
import pages.util_pages.RegisterPage;
import pages.util_pages.ClothingCategories;
import pages.util_pages.AdidasShoesPage;

public class MenusPage extends AnyPage {

	@FindBy(xpath = "//a[@class='ico-logout']")
	private WebElement logoutLink;


	public MenusPage(MainPageManager pages) {
		super(pages);
	}

	public MenusPage ensurePageLoaded() {
		super.ensurePageLoaded();
		waitBig.until(ExpectedConditions.presenceOfElementLocated(By.cssSelector("body")));
		return this;
	}

	public RegisterPage clickRegister() {
		log.info("Click Register link.");
		driver.findElement(By.linkText("Register")).click();
		return pages.registerPage.ensurePageLoaded();
	}

	public HomePage logout() {
		log.info("Click logout button");
		logoutLink.click();
		return pages.homePage.ensurePageLoaded();
	}

	public LoginPage clickLogin() {
		log.info("Click login button");
		driver.findElement(By.linkText("Log in")).click();
		return pages.loginPage;
	}
	
	public ClothingCategories goToApparelCategory() {
		log.info("Go to the 'Apparel' category");
		driver.findElement(By.linkText("Apparel")).click();
		//return pages.clothingCategories.ensurePageLoaded();
		return pages.clothingCategories.ensurePageLoaded();
	}

}