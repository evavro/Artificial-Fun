; Listing generated by Microsoft (R) Optimizing Compiler Version 16.00.40219.01 

	TITLE	C:\Users\Teaja\Documents\Artificial-Fun\LabRavenProjectTest\Common\misc\FrameCounter.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

PUBLIC	??0FrameCounter@@AAE@XZ				; FrameCounter::FrameCounter
PUBLIC	?Instance@FrameCounter@@SAPAV1@XZ		; FrameCounter::Instance
EXTRN	___security_cookie:DWORD
EXTRN	___CxxFrameHandler3:PROC
EXTRN	@__security_check_cookie@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_Shutdown:PROC
EXTRN	__RTC_InitBase:PROC
;	COMDAT ?instance@?1??Instance@FrameCounter@@SAPAV2@XZ@4V2@A
; File c:\users\teaja\documents\artificial-fun\labravenprojecttest\common\misc\framecounter.cpp
_BSS	SEGMENT
?instance@?1??Instance@FrameCounter@@SAPAV2@XZ@4V2@A DQ 01H DUP (?) ; `FrameCounter::Instance'::`2'::instance
_BSS	ENDS
;	COMDAT ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA
_BSS	SEGMENT
?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA DD 01H DUP (?) ; `FrameCounter::Instance'::`2'::$S1
_BSS	ENDS
xdata$x	SEGMENT
__unwindtable$?Instance@FrameCounter@@SAPAV1@XZ DD 0ffffffffH
	DD	FLAT:__unwindfunclet$?Instance@FrameCounter@@SAPAV1@XZ$0
__ehfuncinfo$?Instance@FrameCounter@@SAPAV1@XZ DD 019930522H
	DD	01H
	DD	FLAT:__unwindtable$?Instance@FrameCounter@@SAPAV1@XZ
	DD	2 DUP(00H)
	DD	2 DUP(00H)
	DD	00H
	DD	01H
xdata$x	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
; Function compile flags: /Odtp /RTCsu
rtc$IMZ	ENDS
_TEXT	SEGMENT
__$EHRec$ = -12						; size = 12
?Instance@FrameCounter@@SAPAV1@XZ PROC			; FrameCounter::Instance

; 5    : {

	push	ebp
	mov	ebp, esp
	push	-1
	push	__ehhandler$?Instance@FrameCounter@@SAPAV1@XZ
	mov	eax, DWORD PTR fs:0
	push	eax
	mov	eax, DWORD PTR ___security_cookie
	xor	eax, ebp
	push	eax
	lea	eax, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, eax

; 6    :   static FrameCounter instance;

	mov	eax, DWORD PTR ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA
	and	eax, 1
	jne	SHORT $LN1@Instance
	mov	ecx, DWORD PTR ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA
	or	ecx, 1
	mov	DWORD PTR ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA, ecx
	mov	DWORD PTR __$EHRec$[ebp+8], 0
	mov	ecx, OFFSET ?instance@?1??Instance@FrameCounter@@SAPAV2@XZ@4V2@A
	call	??0FrameCounter@@AAE@XZ			; FrameCounter::FrameCounter
	mov	DWORD PTR __$EHRec$[ebp+8], -1
$LN1@Instance:

; 7    : 
; 8    :   return &instance;

	mov	eax, OFFSET ?instance@?1??Instance@FrameCounter@@SAPAV2@XZ@4V2@A

; 9    : }

	mov	ecx, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, ecx
	pop	ecx
	add	esp, 12					; 0000000cH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_TEXT	ENDS
text$x	SEGMENT
__unwindfunclet$?Instance@FrameCounter@@SAPAV1@XZ$0:
	mov	eax, DWORD PTR ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA
	and	eax, -2					; fffffffeH
	mov	DWORD PTR ?$S1@?1??Instance@FrameCounter@@SAPAV2@XZ@4IA, eax
	ret	0
__ehhandler$?Instance@FrameCounter@@SAPAV1@XZ:
	mov	edx, DWORD PTR [esp+8]
	lea	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [edx-4]
	xor	ecx, eax
	call	@__security_check_cookie@4
	mov	eax, OFFSET __ehfuncinfo$?Instance@FrameCounter@@SAPAV1@XZ
	jmp	___CxxFrameHandler3
text$x	ENDS
?Instance@FrameCounter@@SAPAV1@XZ ENDP			; FrameCounter::Instance
; Function compile flags: /Odtp /RTCsu
; File c:\users\teaja\documents\artificial-fun\labravenprojecttest\common\misc\framecounter.h
;	COMDAT ??0FrameCounter@@AAE@XZ
_TEXT	SEGMENT
_this$ = -4						; size = 4
??0FrameCounter@@AAE@XZ PROC				; FrameCounter::FrameCounter, COMDAT
; _this$ = ecx

; 15   :   FrameCounter():m_lCount(0), m_iFramesElapsed(0){}

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+4], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	esp, ebp
	pop	ebp
	ret	0
??0FrameCounter@@AAE@XZ ENDP				; FrameCounter::FrameCounter
_TEXT	ENDS
END
