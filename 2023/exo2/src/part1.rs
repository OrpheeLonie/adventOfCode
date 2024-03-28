pub fn part1(content: String) -> u32 {
    content.len() as u32
}

fn parse_line() {}

#[cfg(test)]
mod tests {
    use std::fs;

    use super::*;

    #[test]
    fn test_part1() {
        let content = fs::read_to_string("input2").expect("Could not read file in test");
        assert_eq!(part1(content), 4);
    }
}
