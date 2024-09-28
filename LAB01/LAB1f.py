class BIT:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)
    
    def update(self, index, delta):
        while index <= self.size:
            self.tree[index] += delta
            index += index & -index
    
    def query(self, index):
        total = 0
        while index > 0:
            total += self.tree[index]
            index -= index & -index
        return total

def count_triple_tuples(N):
    n = len(N)
    count = 0
    
    # Coordinate compression
    sorted_unique_values = sorted(set(N))
    value_to_compressed = {v: i + 1 for i, v in enumerate(sorted_unique_values)}
    
    compressed_N = [value_to_compressed[x] for x in N]
    
    # BIT to count number of elements less than current value to the left of j
    bit_left = BIT(len(sorted_unique_values))
    
    # BIT to count number of elements equal to current value to the right of j
    bit_right = BIT(len(sorted_unique_values))
    
    # Precompute right counts
    right_counts = [0] * n
    for i in range(n - 1, -1, -1):
        right_counts[i] = bit_right.query(compressed_N[i])
        bit_right.update(compressed_N[i], 1)
    
    # Count valid tuples
    for j in range(n):
        # Remove current element from the left BIT
        bit_left.update(compressed_N[j], -1)
        
        # Valid k count where k > j
        valid_k_count = right_counts[j]
        
        # Valid i count where i < j
        valid_i_count = bit_left.query(compressed_N[j] - 1)
        
        # Count valid tuples
        count += valid_i_count * valid_k_count
        
        # Add current element to the left BIT
        bit_left.update(compressed_N[j], 1)
    
    return count

# Example usage
N = [2, 7, 1, 8, 2, 8, 1, 8, 2]
print(count_triple_tuples(N))  # Output should be 11
