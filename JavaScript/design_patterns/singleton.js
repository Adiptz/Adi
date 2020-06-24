// LAZY
{
function lazySingleton () {
        let instance;

        function createInstance() {
            instance = {name : 'Lazy instance'};
            return instance;
        }

        return {
            getInstance : function(){
                if (!instance) {
                    instance = createInstance();
                }

                return instance;
            }
        };
    }

    let mySingleton = lazySingleton();
    console.log(mySingleton.getInstance());
}

// Eager
{
    let eagerSingleton = (function () {
        const instance = {name : 'Eager instance'};

        return {
            getInstance : function(){
                return instance;
            }
        };
    }());

    console.log(eagerSingleton.getInstance());
}

// Self Defining Function
{
    function selfDefiningSingleton () {
        let instance = {name : 'Self-Defining instance'};

        selfDefiningSingleton = function () {
            return instance;
        };

        return instance;
    }

    let mySingleton = selfDefiningSingleton();
    console.log(mySingleton);
}