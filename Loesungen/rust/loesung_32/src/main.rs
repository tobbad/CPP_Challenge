use lib::{get_int_fromcl, pascal_dreieck};

fn main(){
    
    let line_nr = get_int_fromcl(&String::from("Count of lines ")) as u8;
    
    let lines = pascal_dreieck(line_nr+2);
    for line in lines
    {
        println!("{}", line);
    }
    
}

