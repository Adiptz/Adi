package il.co.ilrd.vending_machine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.function.Consumer;

import il.co.ilrd.vending_machine.VendingMachine.Product;

public class Test {
	static private Consumer<String> view;
    public static void main(String[] args) throws IOException {
        
    	VendingMachine vm = new VendingMachine(createProdList(), msg -> System.out.println(msg));
        vm.start();

        BufferedReader inputBuff = new BufferedReader(new InputStreamReader(System.in));

        label:
        while (true) {
            switch (inputBuff.readLine()) {
                case "pay":
                    vm.insertCoin(5);
                    break;
                case "stop":
                    break label;
                case "cola":
                    vm.chooseProduct(0);
                    break;
                case "sprite":
                    vm.chooseProduct(1);
                    break;
                case "fanta":
                    vm.chooseProduct(2);
                    break;
//                case "click":
//                    vm.chooseProduct(new VendingMachine.Product("Click", 2));
//                    break;
                case "two":
                    vm.insertCoin(2);
                    break;
                case "cancel":
                    vm.cancel();
                    break;
            }
        }

        vm.shutDown();
        System.out.println("Good Job :)");
    }

    private static List<Product> createProdList(){
        List<Product> itemList = new ArrayList();

        itemList.add(new VendingMachine.Product("Cola", 3));
        itemList.add(new VendingMachine.Product("Sprite", 2));
        itemList.add(new VendingMachine.Product("Fanta", 6));

        return itemList;
    }
}
