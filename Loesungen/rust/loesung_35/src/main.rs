use lib::{recursive_size};

fn main(){
    
    
    let lines = recursive_size(env::current_dir()?);
    for line in lines
    {
        println!("{}", line);
    }
    
}

