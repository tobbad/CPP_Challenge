use lib::{Matrix};

fn main(){
    let mut  a = Matrix::new(3,2);
    println!("{}",a );
    //println!("{:?}", a);
    //println!("{}", a);
    let v = [1,2,3,4,5,6];
    a.set(&v);
    //println!("{}", a);
    //println!("{}", a);

}

