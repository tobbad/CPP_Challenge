use lib::{recursive_size};
use std::env;

fn main(){
    
    let root = match env::current_dir()
    {
        Ok(p) => p.into_os_string(),
        Err(e) => {
            panic!("No valid path {}", e);
        }
    };
    let mut res = HashMap::new();
    let lines = recursive_size(root, res);
    for line in lines
    {
        println!("{} {}", line.0, line.1);
    }

    
}

