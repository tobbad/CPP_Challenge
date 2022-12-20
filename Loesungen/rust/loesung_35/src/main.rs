use lib::{recursive_size};
use std::env;

fn main(){
    
    
    let lines = recursive_size(env::current_dir()?.into_os_string());
    for line in lines
    {
        println!("{}", line.1);
    }
    
}

