use lib::{get_int_fromcl, pascal_dreieck};
use factorial::Factorial;

fn main(){
    
    let line_nr = get_int_fromcl(&String::from("Count of lines "));
    
    println!("{}",10_usize.factorial());
    lines = pascal_dreieck(line_nr);
    for line in lines
    {
        println!("{}", line);
    }
    
}

