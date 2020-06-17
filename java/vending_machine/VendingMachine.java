package il.co.ilrd.vending_machine;

import java.time.LocalTime;
import java.util.Collection;
import java.util.List;
import java.util.function.Consumer;

public class VendingMachine {

    private State state = State.INIT;
    private int currBalance;
    private List<Product> products;
    private Consumer<String> view;
    private Thread thread;
    private boolean active = true;
    private LocalTime startTime;

    public VendingMachine(List<Product> products, Consumer<String> view) {
        this.products = products;
        this.view = view;
    }

    /**
     * Initializes and invokes VendingMachine to begin state.
     */
    public void start() {
    	thread = new Thread ( () -> {
    		while (active) {
    			state.timeout(this);
    			try {
    				Thread.sleep(1000);
    			} catch (InterruptedException e) {
    				e.printStackTrace();
    			}
    		}
    	});

    	state.init(this);
    }

    /**
     * Shutdown the VendingMachine.
     */
    public void shutDown() {
        state.shutDown(this);
    }

    /**
     * Insert money into machine.
     * @param coinVlue inserted for transaction.
     */
    public void insertCoin(int coinValue) {
        state.insertCoin(this, coinValue);
    }

    /**
     * Chooses product to buy.
     * @param chosen product.
     * invalid product will not have effect,
     * error message will be displayed in ViewModel.
     */
    public void chooseProduct(int product_index) {
      	Product chosen = products.get(product_index);
    	if (null == chosen) {
    		view.accept("Not In Stock");
        	startTime = LocalTime.now();

    	} else if (currBalance >= chosen.price) {
    		state.chooseProduct(this, products.indexOf(chosen));
    	} else {
    		view.accept(chosen.name +" is cost : " + chosen.price);}
    	startTime = LocalTime.now();

    }

    /**
     * cancels current transaction, and flushes change
     */
    public void cancel() {
        state.cancel(this);
    }
    
    private void returnChange(VendingMachine vm, int productPrice) {
    	vm.view.accept("Change : " + (vm.currBalance - productPrice));
    	vm.currBalance = 0;
    }
    
    private enum State {
     
    	INIT {
            @Override
            void init(VendingMachine vm) { 
            	vm.thread.start();
            	vm.state.setState(vm, IDLE);
            }
            
            @Override
            void handleCurrentState(VendingMachine vm) {
            }
        },

        IDLE {
        	@Override
        	void insertCoin(VendingMachine vm, int coinValue) {
        		COLLECTING_MONEY.insertCoin(vm, coinValue);
        	}

        	@Override
        	void handleCurrentState(VendingMachine vm) {
        		vm.startTime = LocalTime.now();
        	}
        },

        COLLECTING_MONEY {
            
        	@Override
            void insertCoin(VendingMachine vm, int coinValue) {
        		vm.currBalance += coinValue;
        		vm.state.setState(vm, COLLECTING_MONEY);
            }
        	
            @Override
            void chooseProduct(VendingMachine vm, int product_position) {
            	Product chosen = vm.products.get(product_position);
            	vm.returnChange(vm, chosen.price);
        		vm.state.setState(vm, TRANSACTION_COMPLETE);
            }


            @Override
            void timeout(VendingMachine vm) {
            	if (vm.startTime.plusSeconds(10).isBefore(LocalTime.now())) {
            		vm.state.cancel(vm);
            	}
            }
            
            @Override
            void cancel (VendingMachine vm) {
            	vm.returnChange(vm, 0);
            	vm.state.setState(vm, IDLE);
            }

            @Override
            void handleCurrentState (VendingMachine vm) {
            	vm.view.accept("Balance : " + vm.currBalance);
            }
            
        },

        TRANSACTION_COMPLETE {
            @Override
            void timeout(VendingMachine vm) {
            	if (vm.startTime.plusSeconds(5).isBefore(LocalTime.now())) {
            		vm.state.setState(vm, IDLE);
            	}
            }
            
            @Override
            void handleCurrentState (VendingMachine vm) {
            	vm.view.accept("Thanks For Buying");
            }
            
        };

        /*
         *  Will initialize Vending machine, change to waitForProduct state
         * @param vm - current Vending Machine
         */
        void init(VendingMachine vm) {

        }
        
        /*
         *  Will shut down Vending machine, change change active flag to false
         * @param vm - current Vending Machine
         */
        void shutDown(VendingMachine vm) {
        	vm.active = false;

        	try {
					vm.thread.join();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
        		
        }
        /*
         * Handles payment transaction, increases current balance,
         * changes state to WAIT_FOR_PRODUCT if there is sufficient balance.
         */
        void insertCoin(VendingMachine vm, int money) {

        }

        /*
         * Changes selected product in vm, changes state to waitForMoney
         */
        void chooseProduct(VendingMachine vm, int product_position) {

        }

        /*
         * @param vm cancels current transaction,
         *  changes state to waitForProduct
         */
        void cancel(VendingMachine vm){
        }

        /*
         * @param vm 
         *  handles timeout event 
         */
        void timeout (VendingMachine vm) {
        	
        }
        
        /*
         * @param vm 
         * sets start time to current time of state transition
         */
        abstract void handleCurrentState (VendingMachine vm);
        
        /*
         * @param vm 
         * sets start time to current time of state transition
         */
        void setState (VendingMachine vm, State state) {
        	vm.state = state;
        	vm.startTime = LocalTime.now();
        	vm.state.handleCurrentState(vm);
        }
    }

    private Product getProduct(int index) {
    	Product product = products.get(index);

    	if (!products.contains(product)) {
    		return null;
    	}
    	
    	return products.get(index);
    }
    
    public static class Product {
        private String name;
        private int price;

        Product(String name, int price) {
            this.price = price;
            this.name = name;
        }

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((name == null) ? 0 : name.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Product other = (Product) obj;
			if (name == null) {
				if (other.name != null)
					return false;
			} else if (!name.equals(other.name))
				return false;
			return true;
		}

    }

}