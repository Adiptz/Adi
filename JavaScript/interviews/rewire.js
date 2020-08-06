


        queueMicrotask(() => {
            console.log('B')
        });

        setTimeout(() => {
            console.log('C')
        }, 1000);

        console.log('A');