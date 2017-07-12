


#include <jni.h>
#include <stdlib.h> 
#include <stdio.h> 
extern "C" {
#include "eapidef.h"
#include "atc.h"
#include "otc.h"
#include "ptc.h"
}

#include "eu_jgen_notes_api_core_JGenAPI.h"

//------------------------------------------------------------------------------
//	fetchOrderAscOccInfo
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchOrderAscOccInfo
(JNIEnv * env, jobject this_obj, jint toObjectID, jshort ascTypeCode, jint destObjectId) {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");
	jfieldID id_associationSequenceNumber = env->GetFieldID(class_GenApi, "associationSequenceNumber", "I");
	jfieldID id_associationNextObjectID = env->GetFieldID(class_GenApi, "associationNextObjectID", "I");

	ASCSEQ nAscSeqNum		          = (ASCSEQ)0;
	OBJID  nOutObjectId              = (OBJID) 0;

	// execute API call
	jint rc = EApiFetchOrderAscOccInfo((OBJID)       toObjectID,    
                                       (ASCTYPECODE) ascTypeCode, 
                                       (OBJID)       destObjectId,
                                       (PASCSEQ)     &nAscSeqNum,     
                                       (POBJID)      &nOutObjectId);  

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchOrderAscOccInfo failed");
	} else {
		env->SetIntField(this_obj, id_associationSequenceNumber, nAscSeqNum);
		env->SetIntField(this_obj, id_associationNextObjectID, nOutObjectId);
	}
	return nOutObjectId;
}

//------------------------------------------------------------------------------
//	addAssociation
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_addAssociation
  (JNIEnv * env, jobject this_obj, jint fromObjectID, jint toObjectID, jshort ascTypeCode)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiAddAssoc((OBJID)       fromObjectID,
			   (ASCTYPECODE) ascTypeCode,
			   (OBJID)       toObjectID);    

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: addAssociation failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	addObject
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_addObject
  (JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint nOutObjectId = 0;

	// execute API call
	jint rc = EApiAddObject((MODELID) modelid,
			    (OBJTYPECODE) objTypeCode,
			    (POBJID)      &nOutObjectId); 

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: addObject failed");
	}
	return nOutObjectId;
}

//------------------------------------------------------------------------------
//	commit
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_commit
  (JNIEnv * env, jobject this_obj) 
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiCommit(); 

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: commit failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	commitUpdates
//------------------------------------------------------------------------------


JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_commitUpdates
  (JNIEnv * env, jobject this_obj, jstring vendorString)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	
	// retrieve path parameter
	const char* szName;
	szName = env->GetStringUTFChars(vendorString, NULL);

	// execute API call
	jint rc = EApiCommitUpdate((CHARVALUE *) szName); 

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(vendorString, szName);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: commitUpdates failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	countCardManyAsc
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countCardManyAsc
  (JNIEnv * env, jobject this_obj, jint objectID, jshort ascTypeCode)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// execute API call
	jint rc = EApiCountCardManyAsc((OBJID)       objectID,       
                                   (ASCTYPECODE) ascTypeCode,  
                                   (PLCOUNT)     &lCount);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countCardManyAsc failed");
	}
	return lCount;
}

//------------------------------------------------------------------------------
//	countModelNameTypeObjs
//------------------------------------------------------------------------------
JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countModelNameTypeObjs
  (JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode, jshort prpTypeCode, jstring name)

 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// retrieve name parameter
	const char* szName;
	szName = env->GetStringUTFChars(name, NULL);

	// execute API call
	jint rc = EApiCountModelNameTypeObjs((MODELID)     modelid,
                                         (OBJTYPECODE) objTypeCode,
                                         (PRPTYPECODE) prpTypeCode,
                                         (PNAME)       szName,
                                         (PLCOUNT)     &lCount);   
	// release 
	env->ReleaseStringUTFChars(name, szName);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countModelNameTypeObjs failed");
	}
	return lCount;
}


//------------------------------------------------------------------------------
//	countModelObjs
//------------------------------------------------------------------------------
JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countModelObjs
  (JNIEnv * env, jobject this_obj, jint modelid)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jint lCount = 0;

	// execute API call
	jint rc = EApiCountModelObjs((MODELID) modelid,
                                 (PLCOUNT) &lCount);  

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countModelObjs failed");
	}
	return lCount;
}


//------------------------------------------------------------------------------
//	countModelTypeObjs
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countModelTypeObjs
  (JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode)

 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// execute API call
	jint rc = EApiCountModelTypeObjs((MODELID)     modelid,
                                     (OBJTYPECODE) objTypeCode,
                                     (PLCOUNT)     &lCount);     
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countModelTypeObjs failed");
	}
	return lCount;
}

//------------------------------------------------------------------------------
//	deleteAssociation
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_deleteAssociation
  (JNIEnv * env, jobject this_obj, jint fromObjectID, jint toObjectID, jshort ascTypeCode, jboolean triggerFlag)

 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	char flag;
	if (triggerFlag == JNI_FALSE) {
		flag = 'N';
	} else {
		flag = 'Y';
		}

	// execute API call
	jint rc = EApiDelAssoc((OBJID)       fromObjectID,
			   (ASCTYPECODE) ascTypeCode,
			   (OBJID)       toObjectID,
			   (CHARVALUE)   flag);     
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: deleteAssociation failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	deleteObject
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_deleteObject
  (JNIEnv * env, jobject this_obj, jint objectID, jboolean triggerFlag)

  {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	char flag;
	if (triggerFlag == JNI_FALSE) {
		flag = 'N';
	} else {
		flag = 'Y';
		}

	// execute API call
	jint rc = EApiDelObject((OBJID) objectID,
			    (char)  flag); 

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: deleteObject failed");
	}
	return;
}


//------------------------------------------------------------------------------
//	fetchAllModelObjs
//------------------------------------------------------------------------------
JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelObjs
  (JNIEnv * env, jobject this_obj, jint modelid, jint maxCount)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
	POBJID pnArrayObjIds = new long[maxCount]; 
    jintArray jobjects = env->NewIntArray(maxCount);

	// execute API call
	jint rc = EApiFetchAllModelObjects((MODELID) modelid,     
 		                                  (PLCOUNT) &lCount,
 		                                  (POBJID)  pnArrayObjIds);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	env->SetIntArrayRegion(jobjects, 0, maxCount, pnArrayObjIds);
	pnArrayObjIds = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelObjs failed");
	}
	return jobjects;
}

//------------------------------------------------------------------------------
//	fetchModelTypeObjs
//------------------------------------------------------------------------------
JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelTypeObjs
  (JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode, jint maxCount)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
 	POBJID pnArrayObjIds = new long[maxCount]();
    jintArray jobjects = env->NewIntArray(maxCount);

	// execute API call
	jint rc = EApiFetchAllModelTypeObjs((MODELID)     modelid,     
                                        (OBJTYPECODE) objTypeCode,
                                        (PLCOUNT)     &lCount,
                                        (POBJID)      pnArrayObjIds);    
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	env->SetIntArrayRegion(jobjects, 0, maxCount,  pnArrayObjIds);
	pnArrayObjIds = NULL;

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelTypeObjs failed");
	}
	return jobjects;
}

//------------------------------------------------------------------------------
//	fetchCardManyAsc 
//------------------------------------------------------------------------------

JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchCardManyAsc
  (JNIEnv * env, jobject this_obj, jint objectID, jshort ascTypeCode, jint maxCount)

 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
	POBJID pnArrayObjIds = new long[maxCount]; 
    jintArray jobjects = env->NewIntArray(maxCount);

	// execute API call
	jint rc = EApiFetchCardManyAsc((OBJID)       objectID,       
                                   (ASCTYPECODE) ascTypeCode,  
                                   (PLCOUNT)     &lCount,   
                                   (POBJID)      pnArrayObjIds);   
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	env->SetIntArrayRegion(jobjects, 0, maxCount, pnArrayObjIds);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchCardManyAsc failed");
	}
	return jobjects;
}


//------------------------------------------------------------------------------
//	fetchCardOneAsc
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchCardOneAsc
  (JNIEnv * env, jobject this_obj, jint objectID, jshort ascTypeCode)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint destObjectID = 0;

	// execute API call
	jint rc = EApiFetchCardOneAsc((OBJID)       objectID,      
                                 (ASCTYPECODE) ascTypeCode, 
                                 (POBJID)      &destObjectID);   
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchCardOneAsc failed");
	}
	return destObjectID;
}


//------------------------------------------------------------------------------
//	fetchCharArrayPrp
//------------------------------------------------------------------------------

JNIEXPORT jstring JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchCharArrayPrp
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    TEXTVALUE szCharText = {'\0'};

	// execute API call
	jint rc = EApiFetchCharArrayPrp((OBJID)        objectID,    
                                    (PRPTYPECODE)  prpTypeCode,
                                    (PTEXTVALUE)   szCharText);     
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchCharArrayPrp failed");
	} else {
		jname = env->NewStringUTF(szCharText);
	}
	return jname;
}


//------------------------------------------------------------------------------
//	fetchModelInfo
//------------------------------------------------------------------------------
JNIEXPORT jstring JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelInfo
  (JNIEnv * env, jobject this_obj, jint modelid)

{

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");
	jfieldID id_modelCodePage = env->GetFieldID(class_GenApi, "modelCodePage", "S");
	jfieldID id_modelLangCode = env->GetFieldID(class_GenApi, "modelLangCode", "S");
	jfieldID id_modelType = env->GetFieldID(class_GenApi, "modelType", "C");
	jfieldID id_modelStatus = env->GetFieldID(class_GenApi, "modelStatus", "C");
	jfieldID id_modelRelease = env->GetFieldID(class_GenApi, "modelRelease", "Ljava/lang/String;");
	jfieldID id_ownerUserName = env->GetFieldID(class_GenApi, "ownerUserName", "Ljava/lang/String;");

	MODELTYPE    eModelType             = (MODELTYPE)    'D';
	MODELSTATUS  eModelStatus           = (MODELSTATUS)  0;
	CODEPAGE     nCodePage              = (CODEPAGE)     0;
	LANGUAGECODE nLangCode              = (LANGUAGECODE) 0;
	USERID       szOutUserId            = {'\0'};
	TEXTVALUE    szCharText             = {'\0'};
	NAME         szModelName            = {'\0'};
	RELEASE      szRelease              = {'\0'};

	// execute API call
	jint rc = EApiFetchModelInfo((MODELID)      modelid,
                                  (PNAME)         szModelName,
                                  (PMODELTYPE)    &eModelType,           
                                  (PMODELSTATUS)  &eModelStatus,               
                                  (PRELEASE)      szRelease,
                                  (PUSERID)       szOutUserId,
                                  (PCODEPAGE)     &nCodePage,         
                                  (PLANGUAGECODE) &nLangCode);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelInfo failed");
	} else {
		jname = env->NewStringUTF(szModelName);
		env->SetShortField(this_obj, id_modelCodePage, nCodePage);
		env->SetShortField(this_obj, id_modelLangCode, nLangCode);
		env->SetCharField(this_obj, id_modelType, 'D');
		env->SetCharField(this_obj, id_modelStatus, eModelStatus);
		env->SetObjectField(this_obj, id_modelRelease, env->NewStringUTF(szRelease));
		env->SetObjectField(this_obj, id_ownerUserName, env->NewStringUTF(szOutUserId));
	}
	return jname;

}

//------------------------------------------------------------------------------
//	fetchModelNameTypeObjs   
//------------------------------------------------------------------------------
JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelNameTypeObjs
(JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode, jshort prpTypeCode, jstring name)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jint objectId = 0;

	// retrieve path parameter
	const char* szName;
	szName = env->GetStringUTFChars(name, NULL);

	// execute API call
	jint rc = EApiFetchModelNameTypeObjs((MODELID)modelid,
		(OBJTYPECODE) objTypeCode,
		(PRPTYPECODE) prpTypeCode,
		(PNAME) szName,
		(POBJID) &objectId
	);  
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(name, szName);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelNameTypeObjs  failed");
	}
	return objectId;
}


//------------------------------------------------------------------------------
//	fetchModelObjListByNameType
//------------------------------------------------------------------------------
JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelObjListByNameType
  (JNIEnv * env, jobject this_obj, jint modelid, jshort objTypeCode, jshort prpTypeCode, jstring name, jint maxCount)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	

	// retrieve path parameter
	const char* szName;
	szName = env->GetStringUTFChars(name, NULL);

	POBJID pnArrayObjIds = new long[maxCount]; 
    jintArray jobjects = env->NewIntArray(maxCount);

	// execute API call
	jint rc = EApiFetchModelObjListByNameType((MODELID)     modelid,
                                         (OBJTYPECODE) objTypeCode,  
                                         (PRPTYPECODE) prpTypeCode,
                                         (PNAME)       szName,
		                                 (PLCOUNT)     &lCount,
                                         (POBJID)      pnArrayObjIds
										);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);
	env->SetIntArrayRegion(jobjects, 0, maxCount, pnArrayObjIds);
	pnArrayObjIds = NULL;


	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelObjListByNameType  failed");
	}
	return jobjects;
}


//------------------------------------------------------------------------------
//	fetchSingleCharPrp
//------------------------------------------------------------------------------

JNIEXPORT jchar JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSingleCharPrp
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode)

 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jchar szCharText = ' ';

	// execute API call
	jint rc = EApiFetchSingleCharPrp((OBJID)       objectID,    
                                    (PRPTYPECODE) prpTypeCode,
                                    (PCHARVALUE)  &szCharText);      
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSingleCharPrp failed");
	} 
	return szCharText;
}


//------------------------------------------------------------------------------
//	fetchSingleNumericPrp
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSingleNumericPrp
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint nIntPrp = 0;

	// execute API call
	jint rc = EApiFetchSingleNumericPrp((OBJID)       objectID,    
                                       (PRPTYPECODE) prpTypeCode,
                                       (PINTVALUE)   &nIntPrp);        
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSingleNumericPrp");
	} 
	return nIntPrp;
}

//------------------------------------------------------------------------------
//	fetchObjectinfo
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchObjectInfo
  (JNIEnv * env, jobject this_obj, jshort objectID)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");
	jfieldID id_modelID = env->GetFieldID(class_GenApi, "modelID", "I");


    jint nOutModelId = 0;
	jint nObjTypeCode = 0;

	// execute API call
	jint rc = EApiFetchObjectInfo((OBJID) objectID,
                                  (PMODELID)     &nOutModelId,
                                  (POBJTYPECODE) &nObjTypeCode);       
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchObjectInfo");
	} 
	env->SetIntField(this_obj, id_modelID, nOutModelId);

	return nObjTypeCode;
}

//------------------------------------------------------------------------------
//	lock
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_lock
  (JNIEnv * env, jobject this_obj, jint modelid, jint lockType)

  {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiLockModel((MODELID) modelid,     
                            (ENCYLOCKTYPE) lockType);


	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: lock failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	open
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_open
  (JNIEnv * env, jobject this_obj, jstring path, jstring work)

{

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

 
	// retrieve path parameter
	const char* szName;
	szName = env->GetStringUTFChars(path, NULL);

	const char* szWorkName;
	szWorkName = env->GetStringUTFChars(work, NULL);
	//SetCurrentDirectory(szWorkName);


	// execute API call
	jshort rc = EApiOpenModel((PDBPARMS) szName, "jgen_errorlog.txt");
 
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(path, szName);
 
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: open failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	reorderAssociationAftr
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_reorderAssociationAftr
(JNIEnv * env, jobject this_obj, jshort ascTypeCode, jint fromObjectID, jint toObjectID1, jint toObjectID2)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiReordrAssocAftr((OBJID) fromObjectID,
			          (ASCTYPECODE) ascTypeCode,
			          (OBJID)       toObjectID1,
			          (OBJID)       toObjectID2);     
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: reorderAssociationAftr");
	} 
	return;
}

//------------------------------------------------------------------------------
//	reorderAssociationBefr
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_reorderAssociationBefr
  (JNIEnv * env, jobject this_obj, jshort ascTypeCode, jint fromObjectID, jint toObjectID1, jint toObjectID2)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiReordrAssocBefr((OBJID) fromObjectID,
			          (ASCTYPECODE) ascTypeCode,
			          (OBJID)       toObjectID1,
			          (OBJID)       toObjectID2);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: reorderAssociationBefr");
	} 
	return;
}

//------------------------------------------------------------------------------
//	rollback
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_rollback
  (JNIEnv * env, jobject this_obj) 
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiUpRollback();

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: rollback failed");
	}
	return;
}


//------------------------------------------------------------------------------
//	upCharArray
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_upCharArray
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode, jstring value)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	
	// retrieve value parameter
	const char* szValue;
	szValue = env->GetStringUTFChars(value, NULL);

	// execute API call
	jint rc = EApiUpCharArray((OBJID)       objectID,
			      (PRPTYPECODE) prpTypeCode,
			      (CHARVALUE *)   szValue);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(value, szValue);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: upCharArray failed");
	}
	return;
}


//------------------------------------------------------------------------------
//	upNumeric
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_upNumeric
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode, jint value)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiUpNumeric((OBJID) objectID,
			      (PRPTYPECODE) prpTypeCode,
			      (INTVALUE)    value);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: upNumeric failed");
	}
	return;
}


//------------------------------------------------------------------------------
//	upSingleChar
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_upSingleChar
  (JNIEnv * env, jobject this_obj, jint objectID, jshort prpTypeCode, jchar value)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiUpSingleChar((OBJID) objectID,
			       (PRPTYPECODE) prpTypeCode,
			       (CHARVALUE)   value);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: upSingleChar failed");
	}
	return;
}


//------------------------------------------------------------------------------
//	fetchSchemaObjTypeMnem
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaObjTypeMnem
    (JNIEnv * env, jobject this_obj, jstring mnemonic)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jint nObjTypeCode = 0;


	// retrieve path parameter
	const char* szName;
	szName = env->GetStringUTFChars(mnemonic, NULL);

	// execute API call
	jint rc = EApiFetchSchemaObjTypeByMnem((PMNEMONIC)    szName,    
                                           (POBJTYPECODE) &nObjTypeCode);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(mnemonic, szName);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaObjTypeMnem failed");
	}
	return nObjTypeCode;
}

//------------------------------------------------------------------------------
//	unlock
//------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_unlock
  (JNIEnv * env, jobject this_obj, jint modelid)


  {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc =  EApiUnLockModel((MODELID)  modelid);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		// env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: unlock failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	connectToEncy
//------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_connectToEncy
  (JNIEnv * env, jobject this_obj, jstring dbparms)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// retrieve path parameter
	const char* szDBParms;
	szDBParms = env->GetStringUTFChars(dbparms, NULL);

	// execute API call
	jint rc = EApiConnectToEncy((PDBPARMS) szDBParms); 

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(dbparms, szDBParms);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: connectToEncy failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	disconnectEncy
//------------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_disconnectEncy
  (JNIEnv * env, jobject this_obj)

  {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// execute API call
	jint rc = EApiDisconnectEncy();;

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		// env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: disconnectEncy failed");
	}
	return;
}

//------------------------------------------------------------------------------
//	logonUserId
//------------------------------------------------------------------------------
JNIEXPORT void JNICALL Java_eu_jgen_notes_api_core_JGenAPI_logonUserId
  (JNIEnv * env, jobject this_obj, jstring userid)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	// retrieve path parameter
	const char* szUserid;
	szUserid = env->GetStringUTFChars(userid, NULL);

	// execute API call
	jint rc = EApiLogonUserId((PUSERID) szUserid);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	// release 
	env->ReleaseStringUTFChars(userid, szUserid);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: logonUserId failed");
	}
	return;

}


//------------------------------------------------------------------------------
//	fetchEncyModelIds
//------------------------------------------------------------------------------

JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchEncyModelIds
  (JNIEnv * env, jobject this_obj, jint maxCount)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
	POBJID pnArrayMdlIds = new long[maxCount]; 
    jintArray jobjects = env->NewIntArray(maxCount);

	// execute API call
	jint rc = EApiFetchEncyModelIds((PLCOUNT)  &lCount,  
                                    (PMODELID) pnArrayMdlIds);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	env->SetIntArrayRegion(jobjects, 0, maxCount, pnArrayMdlIds);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchEncyModelIds failed");
	}
	return jobjects;
}



//------------------------------------------------------------------------------
//	countEncyModelIds
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countEncyModelIds
  (JNIEnv * env, jobject this_obj)
 {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// execute API call
	jint rc = EApiCountEncyModelIds((PLCOUNT) &lCount);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countEncyModelIds failed");
	}
	return lCount;
}
 
//------------------------------------------------------------------------------
//	fetchSchemaAscForObjType
//------------------------------------------------------------------------------

JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaAscForObjType
  (JNIEnv * env, jobject this_obj, jshort objTypeCode, jint maxCount)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
	PPRPTYPECODE pnArrayAscCodes = new short[maxCount];        
    jintArray jobjects = env->NewIntArray(maxCount);
 
	// execute API call
	jint rc = EApiFetchSchemaAscForObjType((OBJTYPECODE)  objTypeCode,
                                             (PLCOUNT)      &lCount,  
                                             (PPRPTYPECODE) pnArrayAscCodes);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	POBJID pnArrayAscCodesL = new long[maxCount]; 
	int i; 
	for (i=0;  i < maxCount; i++) {
		pnArrayAscCodesL[i] = pnArrayAscCodes[i]; 
	}

	env->SetIntArrayRegion(jobjects, 0, maxCount, pnArrayAscCodesL); 

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaAscForObjType failed");
	}
	return jobjects;
}

//------------------------------------------------------------------------------
//	fetchSchemaPrpForObjType
//------------------------------------------------------------------------------

JNIEXPORT jintArray JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaPrpForObjType
  (JNIEnv * env, jobject this_obj, jshort objTypeCode, jint maxCount)

{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = maxCount;	
	PPRPTYPECODE  pnArrayPrpCodes = new short[maxCount]; 
    jintArray jobjects = env->NewIntArray(maxCount); 

	// execute API call
	jint rc = EApiFetchSchemaPrpForObjType((OBJTYPECODE)  objTypeCode, 
                                           (PLCOUNT)      &lCount,  
                                           (PPRPTYPECODE) pnArrayPrpCodes);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	POBJID  pnArrayPrpCodesL = new long[maxCount]; 
	int i; 
	for (i=0;  i < maxCount; i++) {
		 pnArrayPrpCodesL[i] =  pnArrayPrpCodes[i]; 
	}
	env->SetIntArrayRegion(jobjects, 0, maxCount,  pnArrayPrpCodesL);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaPrpForObjType failed");
	}
	return jobjects;
}

//------------------------------------------------------------------------------
//	countSchemaPrpForObjType
//------------------------------------------------------------------------------


JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countSchemaPrpForObjType
(JNIEnv * env, jobject this_obj, jshort objTypeCode) {
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// execute API call
	jint rc =EApiCountSchemaPrpForObjType((OBJTYPECODE) objTypeCode,
                                           (PLCOUNT)     &lCount);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countSchemaPrpForObjType");
	}
	return lCount;

}

//------------------------------------------------------------------------------
//	countSchemaAscForObjType
//------------------------------------------------------------------------------
 
JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_countSchemaAscForObjType
  (JNIEnv * env, jobject this_obj, jshort objTypeCode)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint lCount = 0;

	// execute API call
		jint rc = EApiCountSchemaAscForObjType((OBJTYPECODE) objTypeCode,
                                             (PLCOUNT)     &lCount);
	
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: countSchemaAscForObjType");
	}
	return lCount;

}

//------------------------------------------------------------------------------
//	fetchSchemaObjTypeInfo
//------------------------------------------------------------------------------


JNIEXPORT jstring JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaObjTypeInfo
(JNIEnv * env, jobject this_obj, jshort objTypeCode) {

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);

	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jfieldID id_objectSchemaAggregateBoundry = env->GetFieldID(class_GenApi, "objectSchemaAggregateBoundry", "C");	
	jfieldID id_objectSchemaPhysicalStructure = env->GetFieldID(class_GenApi, "objectSchemaPhysicalStructure", "I");
	jfieldID id_objectSchemaDivisionTypeCode = env->GetFieldID(class_GenApi, "objectSchemaDivisionTypeCode", "I");
	jfieldID id_objectSchemaScopingTypeCode = env->GetFieldID(class_GenApi, "objectSchemaScopingTypeCode", "C");



	MNEMONIC     szMnemonic             = {'\0'};
	OBJAGGBND    eObjAggBnd             = (OBJAGGBND)    '\0';
	OBJPHYSSTR   nObjPhysStr            = (OBJPHYSSTR)   0;
	DIVTYPECODE  nDivTypeCode           = 0;
	OBJSCOPING   eObjScoping            = (OBJSCOPING)   0;

	// execute API call
	jint rc = EApiFetchSchemaObjTypeInfo((OBJTYPECODE)  objTypeCode,
                                         (PMNEMONIC)    szMnemonic,    
                                         (POBJAGGBND)   &eObjAggBnd,        
                                         (POBJPHYSSTR)  &nObjPhysStr,  
                                         (PDIVTYPECODE) &nDivTypeCode, 
                                         (POBJSCOPING)  &eObjScoping); 
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);


	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaObjTypeInfo failed");
	} else {
		jname = env->NewStringUTF(szMnemonic);
		env->SetCharField(this_obj, id_objectSchemaAggregateBoundry, eObjAggBnd);
        env->SetIntField(this_obj, id_objectSchemaPhysicalStructure, nObjPhysStr);
        env->SetIntField(this_obj, id_objectSchemaDivisionTypeCode, nDivTypeCode);
        env->SetCharField(this_obj, id_objectSchemaScopingTypeCode, eObjScoping);
	}
	return jname;


}

//------------------------------------------------------------------------------
//	fetchSchemaObjTypeByMnem
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaObjTypeByMnem
  (JNIEnv * env, jobject this_obj, jstring mnemonic)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

    jint objTypeCode = 0;
	const char* szMnemonic;
	szMnemonic = env->GetStringUTFChars(mnemonic, NULL);
	// execute API call
	jint rc = EApiFetchSchemaObjTypeByMnem((PMNEMONIC)    szMnemonic,    
                                           (POBJTYPECODE) &objTypeCode);

	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaObjTypeByMnem failed");
	}
	return objTypeCode;

}

//------------------------------------------------------------------------------
//	fetchSchemaPrpTypeInfo
//------------------------------------------------------------------------------

JNIEXPORT jstring JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaPrpTypeInfo
  (JNIEnv * env, jobject this_obj, jshort objTypeCode, jshort prpTypeCode)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jfieldID id_propertySchemaFormat = env->GetFieldID(class_GenApi, "propertySchemaFormat", "C");	
	jfieldID id_propertySchemaColumn = env->GetFieldID(class_GenApi, "propertySchemaColumn", "I");
	jfieldID id_propertySchemaLength = env->GetFieldID(class_GenApi, "propertySchemaLength", "I");
	jfieldID id_propertySchemaMnemonic = env->GetFieldID(class_GenApi, "propertySchemaMnemonic", "Ljava/lang/String;");


    MNEMONIC     szMnemonic             = {'\0'};
    PRPFORMAT    ePrpFormat             = (PRPFORMAT)    0;
    PRPCOLUMN    nPrpColumn             = (PRPCOLUMN)    0;
    PRPLENGTH    nPrpLength             = (PRPLENGTH)    0;


	// execute API call
	jint rc = EApiFetchSchemaPrpTypeInfo((OBJTYPECODE)  objTypeCode,
                                         (PRPTYPECODE)  prpTypeCode,  
                                         (PMNEMONIC)    szMnemonic,    
                                         (PPRPFORMAT)   &ePrpFormat,       
                                         (PPRPCOLUMN)   &nPrpColumn,       
                                         (PPRPLENGTH)   &nPrpLength); 
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);



	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaPrpTypeInfo failed");
	} else {
		jname = env->NewStringUTF(szMnemonic);
        env->SetCharField(this_obj, id_propertySchemaFormat, ePrpFormat);
        env->SetIntField(this_obj, id_propertySchemaColumn, nPrpColumn);
        env->SetIntField(this_obj, id_propertySchemaLength, nPrpLength);
		env->SetObjectField(this_obj, id_propertySchemaMnemonic, env->NewStringUTF(szMnemonic));

 	}
	return jname;
}

//------------------------------------------------------------------------------
//	fetchSchemaCharPrpDflt
//------------------------------------------------------------------------------

JNIEXPORT jchar JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaCharPrpDflt
  (JNIEnv * env, jobject this_obj, jshort objTypeCode, jshort prpTypeCode)
{
	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	 jchar cCharPrp = ' ';

	// execute API call
	jint rc = EApiFetchSchemaCharPrpDflt((OBJTYPECODE) objTypeCode,
                                         (PRPTYPECODE) prpTypeCode,  
                                         (PCHARVALUE)  &cCharPrp);
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaCharPrpDflt");
	} 
	return cCharPrp;
}

//------------------------------------------------------------------------------
//	fetchSchemaIntPrpDflt
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaIntPrpDflt
(JNIEnv * env, jobject this_obj, jshort objTypeCode, jshort prpTypeCode) {

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	INTVALUE    nIntPrp             = (INTVALUE)    0;

	// execute API call
	jint rc = EApiFetchSchemaIntPrpDflt((OBJTYPECODE) objTypeCode,
                                        (PRPTYPECODE) prpTypeCode,  
                                        (PINTVALUE)   &nIntPrp);  
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaIntPrpDflt");
	} 
	return nIntPrp;

}

//------------------------------------------------------------------------------
//	fetchSchemaAscTypeCodeInfo
//------------------------------------------------------------------------------

JNIEXPORT jstring JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchSchemaAscTypeCodeInfo
(JNIEnv * env, jobject this_obj, jshort objTypeCode, jshort ascTypeCode) {

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	jfieldID id_associationSchemaInverseCode = env->GetFieldID(class_GenApi, "associationSchemaInverseCode", "I");	
	jfieldID id_associationSchemaCardinality = env->GetFieldID(class_GenApi, "associationSchemaCardinality", "C");
	jfieldID id_associationSchemaOrderFlag = env->GetFieldID(class_GenApi, "associationSchemaOrderFlag", "C");
	jfieldID id_associationSchemaModifyingReferencingFlag = env->GetFieldID(class_GenApi, "associationSchemaModifyingReferencingFlag", "C");
	jfieldID id_associationSchemaDirection = env->GetFieldID(class_GenApi, "associationSchemaDirection", "C");
	jfieldID id_associationSchemaAggregateActionValue = env->GetFieldID(class_GenApi, "associationSchemaAggregateActionValue", "C");
	jfieldID id_associationSchemaMnemonic = env->GetFieldID(class_GenApi, "associationSchemaMnemonic", "Ljava/lang/String;");

    MNEMONIC     szMnemonic             = {'\0'};
    ASCTYPECODE  nOutAscTypeCode        = 0;
    ASCCARD      eAscCard               = (ASCCARD)      '\0';
    ASCORDER     eAscOrder              = (ASCORDER)     '\0';
    ASCMODREF    eAscModRef             = (ASCMODREF)    '\0';
    ASCDIR       eAscDir                = (ASCDIR)       '\0';
    ASCAGGACT    eAscAggAct             = (ASCAGGACT)    '\0';


	// execute API call
	jint  rc = EApiFetchSchemaAscTypeCodeInfo((OBJTYPECODE)  objTypeCode,
                                             (ASCTYPECODE)  ascTypeCode,   
                                             (PMNEMONIC)    szMnemonic,    
                                             (PASCTYPECODE) &nOutAscTypeCode,   
                                             (PASCCARD)     &eAscCard,      
                                             (PASCORDER)    &eAscOrder,     
                                             (PASCMODREF)   &eAscModRef,    
                                             (PASCDIR)      &eAscDir,       
                                             (PASCAGGACT)   &eAscAggAct);  
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);

	jstring jname = NULL;
	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchSchemaAscTypeInfo failed");
	} else {
		jname = env->NewStringUTF(szMnemonic);
        env->SetIntField(this_obj, id_associationSchemaInverseCode, nOutAscTypeCode);
        env->SetCharField(this_obj, id_associationSchemaCardinality, eAscCard);
        env->SetCharField(this_obj, id_associationSchemaOrderFlag, eAscOrder);
        env->SetCharField(this_obj, id_associationSchemaModifyingReferencingFlag, eAscModRef);
        env->SetCharField(this_obj, id_associationSchemaDirection, eAscDir);
        env->SetCharField(this_obj, id_associationSchemaAggregateActionValue, eAscAggAct);
		env->SetObjectField(this_obj, id_associationSchemaMnemonic, env->NewStringUTF(szMnemonic));

	}
	return jname;
}
//------------------------------------------------------------------------------
//	fetchModelByName
//------------------------------------------------------------------------------
JNIEXPORT jint JNICALL Java_eu_jgen_notes_api_core_JGenAPI_fetchModelByName
(JNIEnv * env, jobject this_obj, jstring modelName) {

	// find returnCode object
	jclass class_GenApi = env->GetObjectClass(this_obj);
	jfieldID id_returnCode = env->GetFieldID(class_GenApi, "returnCode", "I");

	const char* szName;
	szName = env->GetStringUTFChars(modelName, NULL);

    jint nInModelId = 0;

 	jint rc = EApiFetchModelByName((PNAME)    szName, 
                                   (PMODELID) &nInModelId); 
	// set return value
	env->SetIntField(this_obj, id_returnCode, rc);
	// release 
	env->ReleaseStringUTFChars(modelName, szName);

	if (rc != EAPI_SUCCESSFUL_RC) {
		// throw new exception
		env->ThrowNew(env->FindClass("eu/jgen/notes/api/core"), "Method: fetchModelByName failed");
	}
	return nInModelId;
}
