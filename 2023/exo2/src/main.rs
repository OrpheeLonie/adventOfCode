use std::fs;

pub mod part1;

fn main() {
    let content = fs::read_to_string("input").expect("This should have opened a file");

    println!("{}", part1::part1(content));
}
