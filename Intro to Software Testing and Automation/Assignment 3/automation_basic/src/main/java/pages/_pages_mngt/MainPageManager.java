package pages._pages_mngt;

import org.apache.log4j.Logger;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.PageFactory;

import applogic.ApplicationManager1;
import pages._pages_mngt.page_factory.DisplayedElementLocatorFactory;
import pages.super_pages.MenusPage;
import pages.super_pages.Page;
import pages.util_pages.CategoryContentPage;
import pages.util_pages.HomePage;
import pages.util_pages.LoginPage;
import pages.util_pages.RegisterPage;
import pages.util_pages.RegisterSuccessPage;
import pages.util_pages.AdidasShoesPage;
import pages.util_pages.CartPage;
import pages.util_pages.CheckoutPage;
import pages.util_pages.ClothingCategories;
import util.ParamsUtils;
import util.SelUtils;
import util.GenUtils;
import pages.util_pages.ShoesPage;
import pages.util_pages.ThankYouPage;

public class MainPageManager {

	private WebDriver driver;
	public SelUtils su;
	private Logger log;
	private ParamsUtils sessionParams;

	public MenusPage menusPage;
	public LoginPage loginPage;
	public RegisterPage registerPage;
	public RegisterSuccessPage registerSuccessPage;
	public HomePage homePage;
	public CategoryContentPage categoryContentPage;
	public ClothingCategories clothingCategories;
	public ShoesPage shoesPage;
	public AdidasShoesPage adidasShoesPage;
	public CartPage cartPage;
	public CheckoutPage checkoutPage;
	public ThankYouPage thankYouPage;

	public MainPageManager(ApplicationManager1 app) {
		driver = app.getDriver();
		su = app.su;
		log = app.getLogger();
		sessionParams = app.getParamsUtils();

		loginPage = initElements(new LoginPage(this));
		menusPage = initElements(new MenusPage(this));
		registerPage = initElements(new RegisterPage(this));
		registerSuccessPage = initElements(new RegisterSuccessPage(this));
		homePage = initElements(new HomePage(this));
		categoryContentPage = initElements(new CategoryContentPage(this));
		clothingCategories = initElements(new ClothingCategories(this));
		shoesPage = initElements(new ShoesPage(this));
		adidasShoesPage = initElements(new AdidasShoesPage(this));
		cartPage = initElements(new CartPage(this));
		checkoutPage = initElements(new CheckoutPage(this));
		thankYouPage = initElements(new ThankYouPage(this));
	}

	public <T extends Page> T initElements(T page) {
		// PageFactory.initElements(driver, page);
		// PageFactory.initElements(new AjaxElementLocatorFactory(driver, 10),
		// page);
		PageFactory.initElements(new DisplayedElementLocatorFactory(driver, 10), page);
		return page;
	}

	public WebDriver getWebDriver() {
		return driver;
	}

	public Logger gerLogger() {
		return log;
	}

	public ParamsUtils getSessionParams() {
		return sessionParams;
	}

	
}
