import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;

public class OpenAndCopyUpdatePagesText {

    @Test(priority = 4)
    void start() throws InterruptedException {

        WebDriver driver = new EdgeDriver();
        driver.manage().window().maximize();
        driver.get("https://www.promenauts.com/home");
        Thread.sleep(3000);

        //finds the last updated button clicks it and copies the text to output.
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/div[4]/div[2]/div[1]/span/span")).click();
        Thread.sleep(3000);
        WebElement LastUpdated = driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/div[4]/div[2]/div[2]/div[1]/div/span[2]"));
        System.out.println(LastUpdated.getText());

        driver.close();
    } // start

}//class
