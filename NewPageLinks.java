import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;

public class NewPageLinks {

    @Test
    void NewPageLinks() throws InterruptedException {

        WebDriver driver = new EdgeDriver();
        driver.manage().window().maximize();
        driver.get("https://www.promenauts.com/home");
        Thread.sleep(3000);

        // goes through and opens each page link
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[3]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[4]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[2]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[1]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/div[1]/section[3]/div[2]/div/div[1]/div/div/div/div/div/div/div/div/a/div[1]/p")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[1]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/div[1]/section[3]/div[2]/div/div[2]/div/div/div/div/div/div/div/div/a/div[1]/p")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/header/div/div[2]/div[1]/nav/ul/li[1]/div[1]/div/a")).click();
        Thread.sleep(3000);
        driver.findElement(new By.ByXPath("/html/body/div[1]/div/div[2]/div[3]/div/div[1]/section[3]/div[2]/div/div[3]/div/div/div/div/div/div/div/div/a/div[1]/p")).click();
        Thread.sleep(3000);

        driver.close();

    } // newPageLinks

}// class
