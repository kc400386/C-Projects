import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;
public class SearchBar {

    @Test
    void SearchFunction() throws InterruptedException {

        WebDriver driver = new EdgeDriver();

        // Open the browser with the given URL
        // This is for hyperlink on the home page
        String url = "https://www.promenauts.com/";
        driver.get(url);
        driver.manage().window().maximize();

        Thread.sleep(2000);

        // Identify and click the search icon
        driver.findElement(By.cssSelector("#atIdViewHeader > div > div.VLoccc.K5Zlne.QDWEj.U8eYrb > div.Pvc6xe > div.RBEWZc > div > span > span > svg")).click();

        Thread.sleep(1000);

        // identify and type in the search bar
        driver.findElement(By.xpath("/html/body/div[1]/div/div[1]/div[2]/div[3]/div[2]/div/div[1]/div/div[1]/input")).sendKeys("Twinchi");

        Thread.sleep(1000);
        driver.findElement(By.className("vu8Pwe")).click();

        Thread.sleep(5000);

        driver.close();
    }

}// class
