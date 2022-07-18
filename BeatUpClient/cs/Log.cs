static partial class BeatUpClient {
	public interface ILogger {
		void Trace(string message);
		void Debug(string message);
		void Info(string message);
		void Warn(string message);
		void Error(string message);
		void Critical(string message);
	}
	struct DefaultLogger : ILogger {
		public void Trace(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Trace] " + message);
		public void Debug(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Debug] " + message);
		public void Info(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Info] " + message);
		public void Warn(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Warn] " + message);
		public void Error(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Error] " + message);
		public void Critical(string message) =>
			UnityEngine.Debug.Log("[BeatUpClient|Critical] " + message);
	}
}
