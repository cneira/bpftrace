#include "common.h"

namespace bpftrace {
namespace test {
namespace codegen {

TEST(codegen, call_signal_literal)
{
  test("k:f { signal(8); }",
R"EXPECTED(define i64 @"kprobe:f"(i8* nocapture readnone) local_unnamed_addr section "s_kprobe:f_1" {
entry:
  %signal = tail call i64 inttoptr (i64 109 to i64 (i32)*)(i32 8)
  ret i64 0
}
)EXPECTED", false);
}

} // namespace codegen
} // namespace test
} // namespace bpftrace
