use lib::{validate_isbn_10,get_input};

fn main(){
    let isbn = get_input("ISBN: ");

	println!("{}", isbn);
    let a = validate_isbn_10(isbn);
    println!("Given ISBN: {:?}", a);
    let a = validate_isbn_10(String::from("0306406152"));
    println!("Good ISBN: {:?}", a);
    let a = validate_isbn_10(String::from("0306406151"));
    println!("Bad  ISBN: {:?}", a);


}

