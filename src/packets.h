#ifndef PACKETS_H
#define PACKETS_H

/* 
 * AUTO GENERATED; DO NOT TOUCH
 * AUTO GENERATED; DO NOT TOUCH
 * AUTO GENERATED; DO NOT TOUCH
 */

#include "enum.h"
#include <stdint.h>

#define SERIALIZE_BODY(pkt, stype, dtype, data) { \
	fprintf(stderr, "serialize " #stype "\n"); \
	uint8_t *_end = *(pkt); \
	pkt_write##dtype(&_end, data); \
	struct SerializeHeader _serial; \
	_serial.length = _end + 1 - *(pkt); \
	_serial.type = stype; \
	pkt_writeSerializeHeader(pkt, _serial); \
	pkt_write##dtype(pkt, data); \
}
uint8_t pkt_readUint8(const uint8_t **pkt);
uint16_t pkt_readUint16(const uint8_t **pkt);
uint32_t pkt_readUint32(const uint8_t **pkt);
uint64_t pkt_readUint64(const uint8_t **pkt);
#define pkt_readInt8(pkt) (int8_t)pkt_readUint8(pkt)
#define pkt_readInt16(pkt) (int16_t)pkt_readUint16(pkt)
#define pkt_readInt32(pkt) (int32_t)pkt_readUint32(pkt)
#define pkt_readInt64(pkt) (int64_t)pkt_readUint64(pkt)
uint64_t pkt_readVarUint64(const uint8_t **pkt);
uint64_t pkt_readVarUint64(const uint8_t **pkt);
int64_t pkt_readVarInt64(const uint8_t **pkt);
uint32_t pkt_readVarUint32(const uint8_t **pkt);
int32_t pkt_readVarInt32(const uint8_t **pkt);
void pkt_readUint8Array(const uint8_t **pkt, uint8_t *out, uint32_t count);
float pkt_readFloat32(const uint8_t **pkt);
double pkt_readFloat64(const uint8_t **pkt);
void pkt_writeUint8(uint8_t **pkt, uint8_t v);
void pkt_writeUint16(uint8_t **pkt, uint16_t v);
void pkt_writeUint32(uint8_t **pkt, uint32_t v);
void pkt_writeUint64(uint8_t **pkt, uint64_t v);
void pkt_writeVarUint64(uint8_t **pkt, uint64_t v);
void pkt_writeVarInt64(uint8_t **pkt, int64_t v);
void pkt_writeVarUint32(uint8_t **pkt, uint32_t v);
void pkt_writeVarInt32(uint8_t **pkt, int32_t v);
#define pkt_writeInt8Array(pkt, out, count) pkt_writeUint8Array(pkt, (uint8_t*)out, count)
void pkt_writeUint8Array(uint8_t **pkt, const uint8_t *in, uint32_t count);
void pkt_writeFloat32(uint8_t **pkt, float v);
void pkt_writeFloat64(uint8_t **pkt, double v);
ENUM(uint8_t, Platform, {
	Platform_Test,
	Platform_OculusRift,
	Platform_OculusQuest,
	Platform_Steam,
	Platform_PS4,
	Platform_PS4Dev,
	Platform_PS4Cert,
	Platform_Oculus = 1,
})
struct PacketEncryptionLayer {
	_Bool encrypted;
	uint32_t sequenceId;
	uint8_t iv[16];
};
struct PacketEncryptionLayer pkt_readPacketEncryptionLayer(const uint8_t **pkt);
void pkt_writePacketEncryptionLayer(uint8_t **pkt, struct PacketEncryptionLayer in);
struct BaseMasterServerReliableRequest {
	uint32_t requestId;
};
struct BaseMasterServerReliableRequest pkt_readBaseMasterServerReliableRequest(const uint8_t **pkt);
void pkt_writeBaseMasterServerReliableRequest(uint8_t **pkt, struct BaseMasterServerReliableRequest in);
struct BaseMasterServerResponse {
	uint32_t responseId;
};
struct BaseMasterServerResponse pkt_readBaseMasterServerResponse(const uint8_t **pkt);
void pkt_writeBaseMasterServerResponse(uint8_t **pkt, struct BaseMasterServerResponse in);
struct BaseMasterServerReliableResponse {
	uint32_t requestId;
	uint32_t responseId;
};
struct BaseMasterServerReliableResponse pkt_readBaseMasterServerReliableResponse(const uint8_t **pkt);
void pkt_writeBaseMasterServerReliableResponse(uint8_t **pkt, struct BaseMasterServerReliableResponse in);
struct BaseMasterServerAcknowledgeMessage {
	struct BaseMasterServerResponse base;
	_Bool messageHandled;
};
struct BaseMasterServerAcknowledgeMessage pkt_readBaseMasterServerAcknowledgeMessage(const uint8_t **pkt);
void pkt_writeBaseMasterServerAcknowledgeMessage(uint8_t **pkt, struct BaseMasterServerAcknowledgeMessage in);
struct ByteArrayNetSerializable {
	uint32_t length;
	uint8_t data[4096];
};
struct ByteArrayNetSerializable pkt_readByteArrayNetSerializable(const uint8_t **pkt);
void pkt_writeByteArrayNetSerializable(uint8_t **pkt, struct ByteArrayNetSerializable in);
struct String {
	uint32_t length;
	char data[60];
};
struct String pkt_readString(const uint8_t **pkt);
void pkt_writeString(uint8_t **pkt, struct String in);
struct AuthenticationToken {
	Platform platform;
	struct String userId;
	struct String userName;
	struct ByteArrayNetSerializable sessionToken;
};
struct AuthenticationToken pkt_readAuthenticationToken(const uint8_t **pkt);
struct BaseMasterServerMultipartMessage {
	struct BaseMasterServerReliableRequest base;
	uint32_t multipartMessageId;
	uint32_t offset;
	uint32_t length;
	uint32_t totalLength;
	uint8_t data[384];
};
void pkt_writeBaseMasterServerMultipartMessage(uint8_t **pkt, struct BaseMasterServerMultipartMessage in);
struct BitMask128 {
	uint64_t _d0;
	uint64_t _d1;
};
struct BitMask128 pkt_readBitMask128(const uint8_t **pkt);
void pkt_writeBitMask128(uint8_t **pkt, struct BitMask128 in);
struct SongPackMask {
	struct BitMask128 _bloomFilter;
};
struct SongPackMask pkt_readSongPackMask(const uint8_t **pkt);
void pkt_writeSongPackMask(uint8_t **pkt, struct SongPackMask in);
ENUM(uint8_t, BeatmapDifficultyMask, {
	BeatmapDifficultyMask_Easy = 1,
	BeatmapDifficultyMask_Normal = 2,
	BeatmapDifficultyMask_Hard = 4,
	BeatmapDifficultyMask_Expert = 8,
	BeatmapDifficultyMask_ExpertPlus = 16,
	BeatmapDifficultyMask_All = 31,
})
ENUM(uint32_t, GameplayModifierMask, {
	GameplayModifierMask_None = 0,
	GameplayModifierMask_BatteryEnergy = 1,
	GameplayModifierMask_NoFail = 2,
	GameplayModifierMask_InstaFail = 4,
	GameplayModifierMask_NoObstacles = 8,
	GameplayModifierMask_NoBombs = 16,
	GameplayModifierMask_FastNotes = 32,
	GameplayModifierMask_StrictAngles = 64,
	GameplayModifierMask_DisappearingArrows = 128,
	GameplayModifierMask_FasterSong = 256,
	GameplayModifierMask_SlowerSong = 512,
	GameplayModifierMask_NoArrows = 1024,
	GameplayModifierMask_GhostNotes = 2048,
	GameplayModifierMask_SuperFastSong = 4096,
	GameplayModifierMask_ProMode = 8192,
	GameplayModifierMask_ZenMode = 16384,
	GameplayModifierMask_SmallCubes = 32768,
	GameplayModifierMask_All = 65535,
})
struct BeatmapLevelSelectionMask {
	BeatmapDifficultyMask difficulties;
	GameplayModifierMask modifiers;
	struct SongPackMask songPacks;
};
struct BeatmapLevelSelectionMask pkt_readBeatmapLevelSelectionMask(const uint8_t **pkt);
void pkt_writeBeatmapLevelSelectionMask(uint8_t **pkt, struct BeatmapLevelSelectionMask in);
ENUM(uint8_t, DiscoveryPolicy, {
	DiscoveryPolicy_Hidden,
	DiscoveryPolicy_WithCode,
	DiscoveryPolicy_Public,
})
ENUM(uint8_t, InvitePolicy, {
	InvitePolicy_OnlyConnectionOwnerCanInvite,
	InvitePolicy_AnyoneCanInvite,
	InvitePolicy_NobodyCanInvite,
})
ENUM(uint8_t, GameplayServerMode, {
	GameplayServerMode_Countdown,
	GameplayServerMode_Managed,
	GameplayServerMode_QuickStartOneSong,
})
ENUM(uint8_t, SongSelectionMode, {
	SongSelectionMode_Vote,
	SongSelectionMode_Random,
	SongSelectionMode_OwnerPicks,
	SongSelectionMode_RandomPlayerPicks,
})
ENUM(uint8_t, GameplayServerControlSettings, {
	GameplayServerControlSettings_None = 0,
	GameplayServerControlSettings_AllowModifierSelection = 1,
	GameplayServerControlSettings_AllowSpectate = 2,
	GameplayServerControlSettings_All = 3,
})
struct GameplayServerConfiguration {
	int32_t maxPlayerCount;
	DiscoveryPolicy discoveryPolicy;
	InvitePolicy invitePolicy;
	GameplayServerMode gameplayServerMode;
	SongSelectionMode songSelectionMode;
	GameplayServerControlSettings gameplayServerControlSettings;
};
struct GameplayServerConfiguration pkt_readGameplayServerConfiguration(const uint8_t **pkt);
void pkt_writeGameplayServerConfiguration(uint8_t **pkt, struct GameplayServerConfiguration in);
typedef uint32_t ServerCode;
ServerCode StringToServerCode(const char *in, uint32_t len);
char *ServerCodeToString(char *out, ServerCode in);
struct IPEndPoint {
	struct String address;
	uint32_t port;
};
void pkt_writeIPEndPoint(uint8_t **pkt, struct IPEndPoint in);
ENUM(uint8_t, AuthenticateUserResponse_Result, {
	AuthenticateUserResponse_Result_Success,
	AuthenticateUserResponse_Result_Failed,
	AuthenticateUserResponse_Result_UnknownError,
})
ENUM(uint8_t, ConnectToServerResponse_Result, {
	ConnectToServerResponse_Result_Success,
	ConnectToServerResponse_Result_InvalidSecret,
	ConnectToServerResponse_Result_InvalidCode,
	ConnectToServerResponse_Result_InvalidPassword,
	ConnectToServerResponse_Result_ServerAtCapacity,
	ConnectToServerResponse_Result_NoAvailableDedicatedServers,
	ConnectToServerResponse_Result_VersionMismatch,
	ConnectToServerResponse_Result_ConfigMismatch,
	ConnectToServerResponse_Result_UnknownError,
})
ENUM(uint8_t, GetPublicServersResponse_Result, {
	GetPublicServersResponse_Result_Success,
	GetPublicServersResponse_Result_UnknownError,
})
struct BaseConnectToServerRequest {
	struct BaseMasterServerReliableRequest base;
	struct String userId;
	struct String userName;
	uint8_t random[32];
	struct ByteArrayNetSerializable publicKey;
};
struct BaseConnectToServerRequest pkt_readBaseConnectToServerRequest(const uint8_t **pkt);
ENUM(uint8_t, DeliveryMethod, {
	DeliveryMethod_ReliableUnordered,
	DeliveryMethod_Sequenced,
	DeliveryMethod_ReliableOrdered,
	DeliveryMethod_ReliableSequenced,
})
struct Channeled {
	uint16_t sequence;
	DeliveryMethod channelId;
};
struct Channeled pkt_readChanneled(const uint8_t **pkt);
void pkt_writeChanneled(uint8_t **pkt, struct Channeled in);
struct Ack {
	uint16_t sequence;
	DeliveryMethod channelId;
	uint8_t data[9];
};
struct Ack pkt_readAck(const uint8_t **pkt);
void pkt_writeAck(uint8_t **pkt, struct Ack in);
struct Ping {
	uint16_t sequence;
};
struct Ping pkt_readPing(const uint8_t **pkt);
struct Pong {
	uint16_t sequence;
	uint64_t time;
};
void pkt_writePong(uint8_t **pkt, struct Pong in);
struct ConnectRequest {
	uint32_t protocolId;
	uint64_t connectId;
	uint8_t addrlen;
	uint8_t address[38];
	struct String secret;
	struct String userId;
	struct String userName;
	_Bool isConnectionOwner;
};
struct ConnectRequest pkt_readConnectRequest(const uint8_t **pkt);
struct ConnectAccept {
	uint64_t connectId;
	uint8_t connectNum;
	_Bool reusedPeer;
};
void pkt_writeConnectAccept(uint8_t **pkt, struct ConnectAccept in);
struct MtuCheck {
	uint32_t newMtu0;
	uint8_t pad[1423];
	uint32_t newMtu1;
};
struct MtuCheck pkt_readMtuCheck(const uint8_t **pkt);
struct MtuOk {
	uint32_t newMtu0;
	uint8_t pad[1423];
	uint32_t newMtu1;
};
void pkt_writeMtuOk(uint8_t **pkt, struct MtuOk in);
ENUM(uint8_t, PacketProperty, {
	PacketProperty_Unreliable,
	PacketProperty_Channeled,
	PacketProperty_Ack,
	PacketProperty_Ping,
	PacketProperty_Pong,
	PacketProperty_ConnectRequest,
	PacketProperty_ConnectAccept,
	PacketProperty_Disconnect,
	PacketProperty_UnconnectedMessage,
	PacketProperty_MtuCheck,
	PacketProperty_MtuOk,
	PacketProperty_Broadcast,
	PacketProperty_Merged,
	PacketProperty_ShutdownOk,
	PacketProperty_PeerNotFound,
	PacketProperty_InvalidProtocol,
	PacketProperty_NatMessage,
	PacketProperty_Empty,
})
struct NetPacketHeader {
	PacketProperty property;
	uint8_t connectionNumber;
	_Bool isFragmented;
};
struct NetPacketHeader pkt_readNetPacketHeader(const uint8_t **pkt);
void pkt_writeNetPacketHeader(uint8_t **pkt, struct NetPacketHeader in);
struct PlayerStateHash {
	struct BitMask128 bloomFilter;
};
struct PlayerStateHash pkt_readPlayerStateHash(const uint8_t **pkt);
void pkt_writePlayerStateHash(uint8_t **pkt, struct PlayerStateHash in);
struct Color32 {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};
struct Color32 pkt_readColor32(const uint8_t **pkt);
void pkt_writeColor32(uint8_t **pkt, struct Color32 in);
struct MultiplayerAvatarData {
	struct String headTopId;
	struct Color32 headTopPrimaryColor;
	struct Color32 handsColor;
	struct String clothesId;
	struct Color32 clothesPrimaryColor;
	struct Color32 clothesSecondaryColor;
	struct Color32 clothesDetailColor;
	struct Color32 _unused[2];
	struct String eyesId;
	struct String mouthId;
	struct Color32 glassesColor;
	struct Color32 facialHairColor;
	struct Color32 headTopSecondaryColor;
	struct String glassesId;
	struct String facialHairId;
	struct String handsId;
};
struct MultiplayerAvatarData pkt_readMultiplayerAvatarData(const uint8_t **pkt);
void pkt_writeMultiplayerAvatarData(uint8_t **pkt, struct MultiplayerAvatarData in);
ENUM(uint32_t, DisconnectedReason, {
	DisconnectedReason_Unknown,
	DisconnectedReason_UserInitiated,
	DisconnectedReason_Timeout,
	DisconnectedReason_Kicked,
	DisconnectedReason_ServerAtCapacity,
	DisconnectedReason_ServerConnectionClosed,
	DisconnectedReason_MasterServerUnreachable,
	DisconnectedReason_ClientConnectionClosed,
	DisconnectedReason_NetworkDisconnected,
	DisconnectedReason_ServerTerminated,
})
struct RoutingHeader {
	uint8_t remoteConnectionId;
	uint8_t connectionId;
	_Bool encrypted;
};
struct RoutingHeader pkt_readRoutingHeader(const uint8_t **pkt);
void pkt_writeRoutingHeader(uint8_t **pkt, struct RoutingHeader in);
struct SyncTime {
	float syncTime;
};
void pkt_writeSyncTime(uint8_t **pkt, struct SyncTime in);
struct PlayerIdentity {
	struct PlayerStateHash playerState;
	struct MultiplayerAvatarData playerAvatar;
	struct ByteArrayNetSerializable random;
	struct ByteArrayNetSerializable publicEncryptionKey;
};
struct PlayerIdentity pkt_readPlayerIdentity(const uint8_t **pkt);
void pkt_writePlayerIdentity(uint8_t **pkt, struct PlayerIdentity in);
ENUM(uint8_t, InternalMessageType, {
	InternalMessageType_SyncTime,
	InternalMessageType_PlayerConnected,
	InternalMessageType_PlayerIdentity,
	InternalMessageType_PlayerLatencyUpdate,
	InternalMessageType_PlayerDisconnected,
	InternalMessageType_PlayerSortOrderUpdate,
	InternalMessageType_Party,
	InternalMessageType_MultiplayerSession,
	InternalMessageType_KickPlayer,
	InternalMessageType_PlayerStateUpdate,
	InternalMessageType_PlayerAvatarUpdate,
})
ENUM(uint8_t, EntitlementsStatus, {
	EntitlementsStatus_Unknown,
	EntitlementsStatus_NotOwned,
	EntitlementsStatus_NotDownloaded,
	EntitlementsStatus_Ok,
})
ENUM(uint32_t, BeatmapDifficulty, {
	BeatmapDifficulty_Easy,
	BeatmapDifficulty_Normal,
	BeatmapDifficulty_Hard,
	BeatmapDifficulty_Expert,
	BeatmapDifficulty_ExpertPlus,
})
ENUM(uint8_t, EnabledObstacleType, {
	EnabledObstacleType_All,
	EnabledObstacleType_FullHeightOnly,
	EnabledObstacleType_NoObstacles,
})
ENUM(uint8_t, EnergyType, {
	EnergyType_Bar,
	EnergyType_Battery,
})
ENUM(uint8_t, SongSpeed, {
	SongSpeed_Normal,
	SongSpeed_Faster,
	SongSpeed_Slower,
	SongSpeed_SuperFast,
})
ENUM(uint8_t, CannotStartGameReason, {
	CannotStartGameReason_None = 1,
	CannotStartGameReason_AllPlayersSpectating,
	CannotStartGameReason_NoSongSelected,
	CannotStartGameReason_AllPlayersNotInLobby,
	CannotStartGameReason_DoNotOwnSong,
})
ENUM(uint8_t, MultiplayerGameState, {
	MultiplayerGameState_None,
	MultiplayerGameState_Lobby,
	MultiplayerGameState_Game,
})
ENUM(uint8_t, MenuRpcType, {
	MenuRpcType_SetPlayersMissingEntitlementsToLevel,
	MenuRpcType_GetIsEntitledToLevel,
	MenuRpcType_SetIsEntitledToLevel,
	MenuRpcType_InvalidateLevelEntitlementStatuses,
	MenuRpcType_SelectLevelPack,
	MenuRpcType_SetSelectedBeatmap,
	MenuRpcType_GetSelectedBeatmap,
	MenuRpcType_RecommendBeatmap,
	MenuRpcType_ClearRecommendedBeatmap,
	MenuRpcType_GetRecommendedBeatmap,
	MenuRpcType_SetSelectedGameplayModifiers,
	MenuRpcType_GetSelectedGameplayModifiers,
	MenuRpcType_RecommendGameplayModifiers,
	MenuRpcType_ClearRecommendedGameplayModifiers,
	MenuRpcType_GetRecommendedGameplayModifiers,
	MenuRpcType_LevelLoadError,
	MenuRpcType_LevelLoadSuccess,
	MenuRpcType_StartLevel,
	MenuRpcType_GetStartedLevel,
	MenuRpcType_CancelLevelStart,
	MenuRpcType_GetMultiplayerGameState,
	MenuRpcType_SetMultiplayerGameState,
	MenuRpcType_GetIsReady,
	MenuRpcType_SetIsReady,
	MenuRpcType_SetStartGameTime,
	MenuRpcType_CancelStartGameTime,
	MenuRpcType_GetIsInLobby,
	MenuRpcType_SetIsInLobby,
	MenuRpcType_GetCountdownEndTime,
	MenuRpcType_SetCountdownEndTime,
	MenuRpcType_CancelCountdown,
	MenuRpcType_GetOwnedSongPacks,
	MenuRpcType_SetOwnedSongPacks,
	MenuRpcType_RequestKickPlayer,
	MenuRpcType_GetPermissionConfiguration,
	MenuRpcType_SetPermissionConfiguration,
	MenuRpcType_GetIsStartButtonEnabled,
	MenuRpcType_SetIsStartButtonEnabled,
})
typedef uint8_t GameplayRpcType;
typedef uint8_t ScoreSyncStateType;
typedef uint8_t NodePoseSyncStateDeltaType;
typedef uint8_t ScoreSyncStateDeltaType;
ENUM(uint8_t, MultiplayerSessionMessageType, {
	MultiplayerSessionMessageType_MenuRpc,
	MultiplayerSessionMessageType_GameplayRpc,
	MultiplayerSessionMessageType_NodePoseSyncState,
	MultiplayerSessionMessageType_ScoreSyncState,
	MultiplayerSessionMessageType_NodePoseSyncStateDelta,
	MultiplayerSessionMessageType_ScoreSyncStateDelta,
})
struct AuthenticateUserRequest {
	struct BaseMasterServerReliableResponse base;
	struct AuthenticationToken authenticationToken;
};
struct AuthenticateUserRequest pkt_readAuthenticateUserRequest(const uint8_t **pkt);
struct AuthenticateUserResponse {
	struct BaseMasterServerReliableResponse base;
	AuthenticateUserResponse_Result result;
};
void pkt_writeAuthenticateUserResponse(uint8_t **pkt, struct AuthenticateUserResponse in);
struct ConnectToServerResponse {
	struct BaseMasterServerReliableResponse base;
	ConnectToServerResponse_Result result;
	struct String userId;
	struct String userName;
	struct String secret;
	struct BeatmapLevelSelectionMask selectionMask;
	uint8_t flags;
	struct IPEndPoint remoteEndPoint;
	uint8_t random[32];
	struct ByteArrayNetSerializable publicKey;
	ServerCode code;
	struct GameplayServerConfiguration configuration;
	struct String managerId;
};
void pkt_writeConnectToServerResponse(uint8_t **pkt, struct ConnectToServerResponse in);
struct ConnectToServerRequest {
	struct BaseConnectToServerRequest base;
	struct BeatmapLevelSelectionMask selectionMask;
	struct String secret;
	ServerCode code;
	struct GameplayServerConfiguration configuration;
};
struct ConnectToServerRequest pkt_readConnectToServerRequest(const uint8_t **pkt);
ENUM(uint8_t, UserMessageType, {
	UserMessageType_AuthenticateUserRequest,
	UserMessageType_AuthenticateUserResponse,
	UserMessageType_ConnectToServerResponse = 8,
	UserMessageType_ConnectToServerRequest,
	UserMessageType_UserMessageReceivedAcknowledge = 13,
	UserMessageType_UserMultipartMessage,
	UserMessageType_SessionKeepaliveMessage,
	UserMessageType_GetPublicServersRequest,
	UserMessageType_GetPublicServersResponse,
})
ENUM(uint8_t, DedicatedServerMessageType, {
	DedicatedServerMessageType_AuthenticateDedicatedServerRequest,
	DedicatedServerMessageType_AuthenticateDedicatedServerResponse,
	DedicatedServerMessageType_CreateDedicatedServerInstanceRequest = 4,
	DedicatedServerMessageType_CreateDedicatedServerInstanceResponse,
	DedicatedServerMessageType_DedicatedServerInstanceNoLongerAvailableRequest,
	DedicatedServerMessageType_DedicatedServerHeartbeatRequest,
	DedicatedServerMessageType_DedicatedServerHeartbeatResponse,
	DedicatedServerMessageType_DedicatedServerInstanceStatusUpdateRequest = 10,
	DedicatedServerMessageType_DedicatedServerShutDownRequest,
	DedicatedServerMessageType_DedicatedServerPrepareForConnectionRequest,
	DedicatedServerMessageType_DedicatedServerMessageReceivedAcknowledge,
	DedicatedServerMessageType_DedicatedServerMultipartMessage,
	DedicatedServerMessageType_DedicatedServerPrepareForConnectionResponse,
})
struct ClientHelloRequest {
	struct BaseMasterServerReliableRequest base;
	uint8_t random[32];
};
struct ClientHelloRequest pkt_readClientHelloRequest(const uint8_t **pkt);
struct HelloVerifyRequest {
	struct BaseMasterServerReliableResponse base;
	uint8_t cookie[32];
};
void pkt_writeHelloVerifyRequest(uint8_t **pkt, struct HelloVerifyRequest in);
struct ClientHelloWithCookieRequest {
	struct BaseMasterServerReliableRequest base;
	uint32_t certificateResponseId;
	uint8_t random[32];
	uint8_t cookie[32];
};
struct ClientHelloWithCookieRequest pkt_readClientHelloWithCookieRequest(const uint8_t **pkt);
struct ServerHelloRequest {
	struct BaseMasterServerReliableResponse base;
	uint8_t random[32];
	struct ByteArrayNetSerializable publicKey;
	struct ByteArrayNetSerializable signature;
};
void pkt_writeServerHelloRequest(uint8_t **pkt, struct ServerHelloRequest in);
struct ServerCertificateRequest {
	struct BaseMasterServerReliableResponse base;
	uint32_t certificateCount;
	struct ByteArrayNetSerializable certificateList[10];
};
void pkt_writeServerCertificateRequest(uint8_t **pkt, struct ServerCertificateRequest in);
struct ClientKeyExchangeRequest {
	struct BaseMasterServerReliableResponse base;
	struct ByteArrayNetSerializable clientPublicKey;
};
struct ClientKeyExchangeRequest pkt_readClientKeyExchangeRequest(const uint8_t **pkt);
struct ChangeCipherSpecRequest {
	struct BaseMasterServerReliableResponse base;
};
void pkt_writeChangeCipherSpecRequest(uint8_t **pkt, struct ChangeCipherSpecRequest in);
ENUM(uint8_t, HandshakeMessageType, {
	HandshakeMessageType_ClientHelloRequest,
	HandshakeMessageType_HelloVerifyRequest,
	HandshakeMessageType_ClientHelloWithCookieRequest,
	HandshakeMessageType_ServerHelloRequest,
	HandshakeMessageType_ServerCertificateRequest,
	HandshakeMessageType_ClientKeyExchangeRequest = 6,
	HandshakeMessageType_ChangeCipherSpecRequest,
	HandshakeMessageType_HandshakeMessageReceivedAcknowledge,
	HandshakeMessageType_HandshakeMultipartMessage,
})
#ifdef reflect
static const char *const reflect_MessageType = "{MessageType_UserMessage=1,MessageType_DedicatedServerMessage=2,MessageType_HandshakeMessage=3192347326,}";
#endif
typedef uint32_t MessageType;
#define MessageType_UserMessage 1
#define MessageType_DedicatedServerMessage 2
#define MessageType_HandshakeMessage 3192347326u
struct MessageHeader {
	MessageType type;
	uint32_t protocolVersion;
};
struct MessageHeader pkt_readMessageHeader(const uint8_t **pkt);
void pkt_writeMessageHeader(uint8_t **pkt, struct MessageHeader in);
struct SerializeHeader {
	uint32_t length;
	uint8_t type;
};
struct SerializeHeader pkt_readSerializeHeader(const uint8_t **pkt);
void pkt_writeSerializeHeader(uint8_t **pkt, struct SerializeHeader in);
#endif // PACKETS_H
