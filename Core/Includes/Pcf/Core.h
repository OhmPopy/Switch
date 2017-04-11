/// @file
/// @brief Contains include files of Core library.
#pragma once

/// @defgroup Pcf Pcf
/// @brief The base module of the Portable C++ Framework wich aim to be independant from the OS.

#include "Microsoft/Win32/Registry.h"
#include "Microsoft/Win32/RegistryHive.h"
#include "Microsoft/Win32/RegistryKey.h"
#include "Microsoft/Win32/RegistryKeyPermissionCheck.h"
#include "Microsoft/Win32/RegistryOptions.h"
#include "Microsoft/Win32/RegistryValueKind.h"
#include "Microsoft/Win32/RegistryValueOptions.h"
#include "System/Collections/Concurrent/ConcurrentBag.h"
#include "System/Collections/Concurrent/ConcurrentQueue.h"
#include "System/Collections/Concurrent/ConcurrentStack.h"
#include "System/Collections/Concurrent/IProducerConsumerCollection.h"
#include "System/Collections/Generic/Comparer.h"
#include "System/Collections/Generic/Dictionary.h"
#include "System/Collections/Generic/GenericException.h"
#include "System/Collections/Generic/HashSet.h"
#include "System/Collections/Generic/ICollection.h"
#include "System/Collections/Generic/IComparer.h"
#include "System/Collections/Generic/IDictionary.h"
#include "System/Collections/Generic/IEnumerable.h"
#include "System/Collections/Generic/IEnumerator.h"
#include "System/Collections/Generic/IList.h"
#include "System/Collections/Generic/ISet.h"
#include "System/Collections/Generic/KeyValuePair.h"
#include "System/Collections/Generic/LinkedList.h"
#include "System/Collections/Generic/List.h"
#include "System/Collections/Generic/Queue.h"
#include "System/Collections/Generic/SortedDictionary.h"
#include "System/Collections/Generic/SortedSet.h"
#include "System/Collections/Generic/Stack.h"
#include "System/Collections/ObjectModel/Collection.h"
#include "System/Collections/ObjectModel/ReadOnlyCollection.h"
#include "System/Collections/Specialized/StringCollection.h"
#include "System/Collections/Specialized/StringDictionary.h"
#include "System/Collections/Specialized/StringEnumerator.h"
#include "System/Collections/ArrayList.h"
#include "System/Collections/BitArray.h"
#include "System/Collections/Comparer.h"
#include "System/Collections/DictionaryEntry.h"
#include "System/Collections/Hashtable.h"
#include "System/Collections/ICollection.h"
#include "System/Collections/IComparer.h"
#include "System/Collections/IDictionary.h"
#include "System/Collections/IEnumerable.h"
#include "System/Collections/IEnumerator.h"
#include "System/Collections/IList.h"
#include "System/Collections/Queue.h"
#include "System/Collections/Stack.h"
#include "System/ComponentModel/InvalidEnumArgumentException.h"
#include "System/Diagnostics/ConsoleTraceListener.h"
#include "System/Diagnostics/Debug.h"
#include "System/Diagnostics/DefaultTraceListener.h"
#include "System/Diagnostics/NullTraceListener.h"
#include "System/Diagnostics/Process.h"
#include "System/Diagnostics/ProcessStartInfo.h"
#include "System/Diagnostics/ProcessWindowStyle.h"
#include "System/Diagnostics/StackFrame.h"
#include "System/Diagnostics/StackTrace.h"
#include "System/Diagnostics/Stopwatch.h"
#include "System/Diagnostics/TextWriterTraceListener.h"
#include "System/Diagnostics/Trace.h"
#include "System/Diagnostics/TraceEventCache.h"
#include "System/Diagnostics/TraceEventType.h"
#include "System/Diagnostics/TraceFilter.h"
#include "System/Diagnostics/TraceListener.h"
#include "System/Diagnostics/TraceListenerCollection.h"
#include "System/Diagnostics/TraceOptions.h"
#include "System/Diagnostics/TraceSource.h"
#include "System/Globalization/NumberStyles.h"
#include "System/IO/Ports/Handshake.h"
#include "System/IO/Ports/Parity.h"
#include "System/IO/Ports/SerialData.h"
#include "System/IO/Ports/SerialDataReceivedEventArgs.h"
#include "System/IO/Ports/SerialDataReceivedEventHandler.h"
#include "System/IO/Ports/SerialError.h"
#include "System/IO/Ports/SerialErrorReceivedEventArgs.h"
#include "System/IO/Ports/SerialErrorReceivedEventHandler.h"
#include "System/IO/Ports/SerialPinChange.h"
#include "System/IO/Ports/SerialPinChangedEventArgs.h"
#include "System/IO/Ports/SerialPinChangedEventHandler.h"
#include "System/IO/Ports/SerialPort.h"
#include "System/IO/Ports/StopBits.h"
#include "System/IO/BinaryReader.h"
#include "System/IO/BinaryWriter.h"
#include "System/IO/Compression.h"
#include "System/IO/Directory.h"
#include "System/IO/DirectoryInfo.h"
#include "System/IO/DirectoryNotFoundException.h"
#include "System/IO/DriveInfo.h"
#include "System/IO/DriveNotFoundException.h"
#include "System/IO/DriveType.h"
#include "System/IO/EndOfStreamException.h"
#include "System/IO/ErrorEventArgs.h"
#include "System/IO/File.h"
#include "System/IO/FileAccess.h"
#include "System/IO/FileAttributes.h"
#include "System/IO/FileFormatException.h"
#include "System/IO/FileInfo.h"
#include "System/IO/FileLoadException.h"
#include "System/IO/FileMode.h"
#include "System/IO/FileNotFoundException.h"
#include "System/IO/FileShare.h"
#include "System/IO/FileStream.h"
#include "System/IO/FileSystemEventArgs.h"
#include "System/IO/FileSystemInfo.h"
#include "System/IO/InternalBufferOverflowException.h"
#include "System/IO/InvalidDataException.h"
#include "System/IO/IOException.h"
#include "System/IO/IsolatedStorage.h"
#include "System/IO/MemoryStream.h"
#include "System/IO/Packaging.h"
#include "System/IO/Path.h"
#include "System/IO/PathTooLongException.h"
#include "System/IO/Pipes.h"
#include "System/IO/PipeException.h"
#include "System/IO/SeekOrigin.h"
#include "System/IO/Stream.h"
#include "System/IO/StreamReader.h"
#include "System/IO/StreamWriter.h"
#include "System/IO/StringReader.h"
#include "System/IO/StringWriter.h"
#include "System/IO/TextReader.h"
#include "System/IO/TextWriter.h"
#include "System/IO/WatcherChangeTypes.h"
#include "System/Linq/Enumerable.h"
#include "System/Net/Sockets/AddressFamily.h"
#include "System/Net/Sockets/IOControlCode.h"
#include "System/Net/Sockets/IPv6MulticastOption.h"
#include "System/Net/Sockets/LingerOption.h"
#include "System/Net/Sockets/MulticastOption.h"
#include "System/Net/Sockets/NetworkStream.h"
#include "System/Net/Sockets/ProtocolFamily.h"
#include "System/Net/Sockets/ProtocolType.h"
#include "System/Net/Sockets/SelectMode.h"
#include "System/Net/Sockets/Socket.h"
#include "System/Net/Sockets/SocketError.h"
#include "System/Net/Sockets/SocketException.h"
#include "System/Net/Sockets/SocketFlags.h"
#include "System/Net/Sockets/SocketInformation.h"
#include "System/Net/Sockets/SocketInformationOptions.h"
#include "System/Net/Sockets/SocketOptionLevel.h"
#include "System/Net/Sockets/SocketOptionName.h"
#include "System/Net/Sockets/SocketShutdown.h"
#include "System/Net/Sockets/SocketType.h"
#include "System/Net/Sockets/TcpClient.h"
#include "System/Net/Sockets/TcpListener.h"
#include "System/Net/Sockets/UdpClient.h"
#include "System/Net/WebSockets/ClientWebSocket.h"
#include "System/Net/WebSockets/WebSocket.h"
#include "System/Net/WebSockets/WebSocketCloseStatus.h"
#include "System/Net/WebSockets/WebSocketMessageType.h"
#include "System/Net/WebSockets/WebSocketState.h"
#include "System/Net/CookieException.h"
#include "System/Net/Dns.h"
#include "System/Net/DnsEndPoint.h"
#include "System/Net/EndPoint.h"
#include "System/Net/FtpStatusCode.h"
#include "System/Net/FtpWebRequest.h"
#include "System/Net/FtpWebResponse.h"
#include "System/Net/HttpListenerException.h"
#include "System/Net/HttpStatusCode.h"
#include "System/Net/HttpWebRequest.h"
#include "System/Net/HttpWebResponse.h"
#include "System/Net/IPAddress.h"
#include "System/Net/IPEndPoint.h"
#include "System/Net/IPHostEntry.h"
#include "System/Net/NetworkCredential.h"
#include "System/Net/ProtocolViolationException.h"
#include "System/Net/SocketAddress.h"
#include "System/Net/WebException.h"
#include "System/Net/WebRequest.h"
#include "System/Net/WebRequestMethods.h"
#include "System/Net/WebResponse.h"
#include "System/Runtime/Serialization/Formatter.h"
#include "System/Runtime/Serialization/ISerializable.h"
#include "System/Runtime/Serialization/IFormatter.h"
#include "System/Runtime/Serialization/SerializationException.h"
#include "System/Runtime/Serialization/SerializationEntry.h"
#include "System/Runtime/Serialization/SerializationInfo.h"
#include "System/Security/HostProtectionException.h"
#include "System/Security/SecureString.h"
#include "System/Security/SecurityException.h"
#include "System/Security/VerificationException.h"
#include "System/Security/XmlSyntaxException.h"
#include "System/Text/ANSIEncoding.h"
#include "System/Text/ASCIIEncoding.h"
#include "System/Text/Decoder.h"
#include "System/Text/Encoder.h"
#include "System/Text/Encoding.h"
#include "System/Text/StringBuilder.h"
#include "System/Text/UTF32Encoding.h"
#include "System/Text/UTF8Encoding.h"
#include "System/Text/UnicodeEncoding.h"
#include "System/Threading/Tasks/ITask.h"
#include "System/Threading/Tasks/Parallel.h"
#include "System/Threading/Tasks/Task.h"
#include "System/Threading/Tasks/TaskStatus.h"
#include "System/Threading/Tasks/TaskTResult.h"
#include "System/Threading/AbandonedMutexException.h"
#include "System/Threading/AutoResetEvent.h"
#include "System/Threading/Barrier.h"
#include "System/Threading/BarrierPostPhaseException.h"
#include "System/Threading/EventResetMode.h"
#include "System/Threading/EventWaitHandle.h"
#include "System/Threading/Interlocked.h"
#include "System/Threading/LockGuard.h"
#include "System/Threading/LockRecursionException.h"
#include "System/Threading/ManualResetEvent.h"
#include "System/Threading/Monitor.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/ParameterizedThreadStart.h"
#include "System/Threading/RegisteredWaitHandle.h"
#include "System/Threading/Semaphore.h"
#include "System/Threading/SemaphoreFullException.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadLocal.h"
#include "System/Threading/ThreadAbortException.h"
#include "System/Threading/ThreadInterruptedException.h"
#include "System/Threading/ThreadPool.h"
#include "System/Threading/ThreadPriority.h"
#include "System/Threading/ThreadStart.h"
#include "System/Threading/ThreadStartException.h"
#include "System/Threading/ThreadState.h"
#include "System/Threading/ThreadStateException.h"
#include "System/Threading/TimeOut.h"
#include "System/Threading/Timer.h"
#include "System/Threading/TimerCallback.h"
#include "System/Threading/TryLockGuard.h"
#include "System/Threading/WaitHandle.h"
#include "System/Threading/WaitHandleCannotBeOpenedException.h"
#include "System/AccessViolationException.h"
#include "System/Action.h"
#include "System/AggregateException.h"
#include "System/AppDomainUnloadedException.h"
#include "System/ArgumentException.h"
#include "System/ArgumentNullException.h"
#include "System/ArgumentOutOfRangeException.h"
#include "System/ArithmeticException.h"
#include "System/Array.h"
#include "System/ArraySegment.h"
#include "System/ArrayTypeMismatchException.h"
#include "System/AsyncCallback.h"
#include "System/BadImageFormatException.h"
#include "System/BitConverter.h"
#include "System/Boolean.h"
#include "System/BoxEnum.h"
#include "System/Buffer.h"
#include "System/Byte.h"
#include "System/CannotUnloadAppDomainException.h"
#include "System/Char.h"
#include "System/CharEnumerator.h"
#include "System/Comparison.h"
#include "System/Console.h"
#include "System/ConsoleColor.h"
#include "System/ConsoleKey.h"
#include "System/ConsoleKeyInfo.h"
#include "System/ConsoleModifiers.h"
#include "System/ContextMarshalException.h"
#include "System/Convert.h"
#include "System/DataMisalignedException.h"
#include "System/DateTime.h"
#include "System/DateTimeKind.h"
#include "System/DayOfWeek.h"
#include "System/Decimal.h"
#include "System/Delegate.h"
#include "System/DivideByZeroException.h"
#include "System/DllNotFoundException.h"
#include "System/Double.h"
#include "System/DuplicateWaitObjectException.h"
#include "System/Enum.h"
#include "System/Environment.h"
#include "System/EntryPointNotFoundException.h"
#include "System/EventArgs.h"
#include "System/EventHandler.h"
#include "System/ExecutionEngineException.h"
#include "System/Exception.h"
#include "System/FieldAccessException.h"
#include "System/FormatException.h"
#include "System/FormatProvider.h"
#include "System/Func.h"
#include "System/Guid.h"
#include "System/Hash.h"
#include "System/IAsyncResult.h"
#include "System/ICloneable.h"
#include "System/IComparable.h"
#include "System/IConvertible.h"
#include "System/ICustomFormatter.h"
#include "System/IFormatProvider.h"
#include "System/IFormattable.h"
#include "System/IndexOutOfRangeException.h"
#include "System/Int16.h"
#include "System/Int32.h"
#include "System/Int64.h"
#include "System/IntPtr.h"
#include "System/InsufficientExecutionStackException.h"
#include "System/InsufficientMemoryException.h"
#include "System/InvalidCastException.h"
#include "System/InvalidOperationException.h"
#include "System/InvalidProgramException.h"
#include "System/InvalidTimeZoneException.h"
#include "System/Math.h"
#include "System/MemberAccessException.h"
#include "System/MethodAccessException.h"
#include "System/MissingFieldException.h"
#include "System/MissingMemberException.h"
#include "System/MissingMethodException.h"
#include "System/MulticastNotSupportedException.h"
#include "System/NotFiniteNumberException.h"
#include "System/NotImplementedException.h"
#include "System/NotSupportedException.h"
#include "System/NullPointerException.h"
#include "System/NullReferenceException.h"
#include "System/NullType.h"
#include "System/Nullable.h"
#include "System/NumberRepresentationBase.h"
#include "System/Object.h"
#include "System/ObjectClosedException.h"
#include "System/ObjectDisposedException.h"
#include "System/OperatingSystem.h"
#include "System/OperationCanceledException.h"
#include "System/OutOfMemoryException.h"
#include "System/OverflowException.h"
#include "System/PlatformID.h"
#include "System/PlatformNotSupportedException.h"
#include "System/Predicate.h"
#include "System/Random.h"
#include "System/RankException.h"
#include "System/SByte.h"
#include "System/Single.h"
#include "System/StackOverflowException.h"
#include "System/String.h"
#include "System/StringSplitOptions.h"
#include "System/SystemException.h"
#include "System/SystemVersion.h"
#include "System/TimeoutException.h"
#include "System/TimeSpan.h"
#include "System/TimeZoneInfo.h"
#include "System/TimeZoneNotFoundException.h"
#include "System/Tuple.h"
#include "System/TupleImpl.h"
#include "System/Type.h"
#include "System/TypeAccessException.h"
#include "System/TypeCode.h"
#include "System/TypeInitializationException.h"
#include "System/TypeUnloadedException.h"
#include "System/UInt16.h"
#include "System/UInt32.h"
#include "System/UInt64.h"
#include "System/UIntPtr.h"
#include "System/UnauthorizedAccessException.h"
#include "System/Uri.h"
#include "System/UriComponents.h"
#include "System/UriFormat.h"
#include "System/UriFormatException.h"
#include "System/UriKind.h"
#include "System/UriHostNameType.h"
#include "System/UriPartial.h"
#include "System/UriTemplateMatchException.h"
#include "System/ValueType.h"
#include "System/Version.h"
#include "Abstract.h"
#include "Any.h"
#include "As.h"
#include "Async.h"
#include "Await.h"
#include "Boxing.h"
#include "CurrentInformation.h"
#include "ExcPtr.h"
#include "InitializerList.h"
#include "Interface.h"
#include "Is.h"
#include "LiteralOperatorConverter.h"
#include "Lock.h"
#include "Move.h"
#include "Property.h"
#include "Ref.h"
#include "RefPtr.h"
#include "Startup.h"
#include "Static.h"
#include "Types.h"
#include "UniquePtr.h"
#include "Unused.h"
#include "Using.h"
#include "Var.h"
