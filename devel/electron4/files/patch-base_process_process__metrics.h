--- base/process/process_metrics.h.orig	2019-03-15 06:36:56 UTC
+++ base/process/process_metrics.h
@@ -41,7 +41,7 @@ namespace base {
 // Full declaration is in process_metrics_iocounters.h.
 struct IoCounters;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -51,7 +51,7 @@ struct PageFaultCounts {
   int64_t minor;
   int64_t major;
 };
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Convert a POSIX timeval to microseconds.
 BASE_EXPORT int64_t TimeValToMicroseconds(const struct timeval& tv);
@@ -177,7 +177,7 @@ class BASE_EXPORT ProcessMetrics {
   // otherwise.
   bool GetIOCounters(IoCounters* io_counters) const;
 
-#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Returns the number of file descriptors currently open by the process, or
   // -1 on error.
   int GetOpenFdCount() const;
@@ -185,16 +185,16 @@ class BASE_EXPORT ProcessMetrics {
   // Returns the soft limit of file descriptors that can be opened by the
   // process, or -1 on error.
   int GetOpenFdSoftLimit() const;
-#endif  // defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
   // Minor and major page fault count as reported by /proc/[pid]/stat.
   // Returns true for success.
   bool GetPageFaultCounts(PageFaultCounts* counts) const;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   // Returns total memory usage of malloc.
   size_t GetMallocUsage();
@@ -206,7 +206,7 @@ class BASE_EXPORT ProcessMetrics {
   ProcessMetrics(ProcessHandle process, PortProvider* port_provider);
 #endif  // !defined(OS_MACOSX) || defined(OS_IOS)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_MACOSX)
@@ -229,7 +229,7 @@ class BASE_EXPORT ProcessMetrics {
   TimeDelta last_cumulative_cpu_;
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -275,7 +275,7 @@ BASE_EXPORT void IncreaseFdLimitTo(unsigned int max_de
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -308,7 +308,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -323,7 +323,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -333,7 +333,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int dirty = 0;
   int reclaimable = 0;
 #endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) ||
-        // defined(OS_FUCHSIA)
+        // defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   int shmem = 0;
@@ -361,7 +361,7 @@ BASE_EXPORT bool GetSystemMemoryInfo(SystemMemoryInfoK
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
