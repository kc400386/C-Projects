import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.Test;

public class SearchBoxTestWithoutInput {

    @Test
    void SearchBoxWithoutInput() throws InterruptedException {

        WebDriver driver = new EdgeDriver();
        driver.manage().window().maximize();
        driver.get("https://www.promenauts.com/");
        Thread.sleep(3000);

        // opens search
        driver.findElement(By.cssSelector("#atIdViewHeader > div > div.VLoccc.K5Zlne.QDWEj.U8eYrb > div.Pvc6xe > div.RBEWZc > div > span > span > svg")).click();
        Thread.sleep(3000);

        // test to see if search will search without input
        driver.findElement(By.xpath("/html/body/div[1]/div/div[1]/div[2]/div[3]/div[2]/div/div[1]/div/div[1]/input")).sendKeys("");
        driver.findElement(By.className("vu8Pwe")).click();
        Thread.sleep(5000);

        driver.close();

    } // SearchBoxWithoutInput
}// class
