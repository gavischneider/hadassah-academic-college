package util;

import org.openqa.selenium.By;
import org.openqa.selenium.support.ui.ExpectedConditions;

import pages._pages_mngt.MainPageManager;
import pages.super_pages.MenusPage;

public class ShoesPage extends MenusPage{

	public ShoesPage(MainPageManager pages) {
		super(pages);
		// TODO Auto-generated constructor stub
	}

	public ShoesPage ensurePageLoaded() {
		 super.ensurePageLoaded();
		   
		 waitBig.until(ExpectedConditions.visibilityOf(driver.findElement(By.xpath(
					"//div[@class='description' and contains(text(),'adidas')]/..//span[contains(@class,'actual-price')]"))));
		   
		 return this;
	}
	
	public String rememberPrice() {
		String price = driver.findElement(By.xpath(
				"//div[@class='description' and contains(text(),'adidas')]/..//span[contains(@class,'actual-price')]"))
				.getText();
		return price;
	}
	
	public AdidasShoesPage goToAdidasShoesPage() {
		log.info("Click on picture");
		driver.findElement(
				By.xpath("//div[@class='picture']//img[contains(@title,'adidas')]"))
				.click();
		GenUtils.sleepMillis(3000);// wait item description page is loaded
		
		return pages.adidasShoesPage.ensurePageLoaded();
	}

}
