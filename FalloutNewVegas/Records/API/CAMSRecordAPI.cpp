/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is CBash code.
 *
 * The Initial Developer of the Original Code is
 * Waruddar.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
#include "..\..\..\Common.h"
#include "..\CAMSRecord.h"

namespace FNV
{
UINT32 CAMSRecord::GetFieldAttribute(FIELD_IDENTIFIERS, UINT32 WhichAttribute)
    {
    switch(FieldID)
        {
        case 0: //recType
            return GetType();
        case 1: //flags1
            return UINT32_FLAG_FIELD;
        case 2: //fid
            return FORMID_FIELD;
        case 3: //versionControl1
            switch(WhichAttribute)
                {
                case 0: //fieldType
                    return UINT8_ARRAY_FIELD;
                case 1: //fieldSize
                    return 4;
                default:
                    return UNKNOWN_FIELD;
                }
            return UNKNOWN_FIELD;
        case 4: //eid
            return ISTRING_FIELD;
        case 5: //formVersion
            return UINT16_FIELD;
        case 6: //versionControl2
            switch(WhichAttribute)
                {
                case 0: //fieldType
                    return UINT8_ARRAY_FIELD;
                case 1: //fieldSize
                    return 2;
                default:
                    return UNKNOWN_FIELD;
                }
            return UNKNOWN_FIELD;
        case 7: //modPath
            return ISTRING_FIELD;
        case 8: //modb
            return FLOAT32_FIELD;
        case 9: //modt_p
            switch(WhichAttribute)
                {
                case 0: //fieldType
                    return UINT8_ARRAY_FIELD;
                case 1: //fieldSize
                    return MODL.IsLoaded() ? MODL->MODT.GetSize() : 0;
                default:
                    return UNKNOWN_FIELD;
                }
            return UNKNOWN_FIELD;
        case 10: //altTextures
            if(!MODL.IsLoaded())
                return UNKNOWN_FIELD;

            if(ListFieldID == 0) //altTextures
                {
                switch(WhichAttribute)
                    {
                    case 0: //fieldType
                        return LIST_FIELD;
                    case 1: //fieldSize
                        return MODL->Textures.size();
                    default:
                        return UNKNOWN_FIELD;
                    }
                }

            if(ListIndex >= MODL->Textures.size())
                return UNKNOWN_FIELD;

            switch(ListFieldID)
                {
                case 1: //name
                    return STRING_FIELD;
                case 2: //texture
                    return FORMID_FIELD;
                case 3: //index
                    return SINT32_FIELD;
                default:
                    return UNKNOWN_FIELD;
                }

        case 13: //modelFlags
            return UINT8_FIELD;
        case 14: //data DATA ,, Struct
            return UINT32_FIELD;
        case 15: //data DATA ,, Struct
            return UINT32_FIELD;
        case 16: //data DATA ,, Struct
            return UINT32_FIELD;
        case 17: //data DATA ,, Struct
            return UINT32_FIELD;
        case 18: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 19: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 20: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 21: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 22: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 23: //data DATA ,, Struct
            return FLOAT32_FIELD;
        case 24: //mnam Image Space Modifier
            return FORMID_FIELD;
        default:
            return UNKNOWN_FIELD;
        }
    return UNKNOWN_FIELD;
    }

void * CAMSRecord::GetField(FIELD_IDENTIFIERS, void **FieldValues)
    {
    switch(FieldID)
        {
        case 1: //flags1
            return &flags;
        case 2: //fid
            return &formID;
        case 3: //versionControl1
            *FieldValues = &flagsUnk;
            return NULL;
        case 4: //eid
            return EDID.value;
        case 5: //formVersion
            return &formVersion;
        case 6: //versionControl2
            *FieldValues = &versionControl2[0];
            return NULL;
        case 7: //modPath
            return MODL.IsLoaded() ? MODL->MODL.value : NULL;
        case 8: //modb
            return MODL.IsLoaded() ? &MODL->MODB.value : NULL;
        case 9: //modt_p
            *FieldValues = MODL.IsLoaded() ? MODL->MODT.value : NULL;
            return NULL;
        case 10: //mods Alternate Textures
            return MODL.IsLoaded() ? MODL->MODS.value : NULL;
        case 11: //mods Alternate Textures
            return MODL.IsLoaded() ? &MODL->MODS->value11 : NULL;
        case 12: //mods Alternate Textures
            return MODL.IsLoaded() ? &MODL->MODS->value12 : NULL;
        case 13: //modelFlags
            return MODL.IsLoaded() ? &MODL->MODD->value13 : NULL;
        case 14: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value14 : NULL;
        case 15: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value15 : NULL;
        case 16: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value16 : NULL;
        case 17: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value17 : NULL;
        case 18: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value18 : NULL;
        case 19: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value19 : NULL;
        case 20: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value20 : NULL;
        case 21: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value21 : NULL;
        case 22: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value22 : NULL;
        case 23: //data DATA ,, Struct
            return DATA.IsLoaded() ? &DATA->value23 : NULL;
        case 24: //mnam Image Space Modifier
            return MNAM.IsLoaded() ? &MNAM->value24 : NULL;
        default:
            return NULL;
        }
    return NULL;
    }

bool CAMSRecord::SetField(FIELD_IDENTIFIERS, void *FieldValue, UINT32 ArraySize)
    {
    switch(FieldID)
        {
        case 1: //flags1
            SetHeaderFlagMask(*(UINT32 *)FieldValue);
            break;
        case 3: //versionControl1
            if(ArraySize != 4)
                break;
            ((UINT8ARRAY)&flagsUnk)[0] = ((UINT8ARRAY)FieldValue)[0];
            ((UINT8ARRAY)&flagsUnk)[1] = ((UINT8ARRAY)FieldValue)[1];
            ((UINT8ARRAY)&flagsUnk)[2] = ((UINT8ARRAY)FieldValue)[2];
            ((UINT8ARRAY)&flagsUnk)[3] = ((UINT8ARRAY)FieldValue)[3];
            break;
        case 4: //eid
            EDID.Copy((STRING)FieldValue);
            break;
        case 5: //formVersion
            formVersion = *(UINT16 *)FieldValue;
            break;
        case 6: //versionControl2
            if(ArraySize != 2)
                break;
            versionControl2[0] = ((UINT8ARRAY)FieldValue)[0];
            versionControl2[1] = ((UINT8ARRAY)FieldValue)[1];
            break;
        case 7: //modPath
            MODL.Load();
            MODL->MODL.Copy((STRING)FieldValue);
            break;
        case 8: //modb
            MODL.Load();
            MODL->MODB.value = *(FLOAT32 *)FieldValue;
            break;
        case 9: //modt_p
            MODL.Load();
            MODL->MODT.Copy((UINT8ARRAY)FieldValue, ArraySize);
            break;
        case 10: //mods Alternate Textures
            MODL.Load();
            MODL->MODS.Copy((STRING)FieldValue);
            break;
        case 11: //mods Alternate Textures
            MODL.Load();
            MODL->MODS.Load();
            MODL->MODS->value11 = *(FORMID *)FieldValue;
            return true;
        case 12: //mods Alternate Textures
            MODL.Load();
            MODL->MODS.Load();
            MODL->MODS->value12 = *(SINT32 *)FieldValue;
            break;
        case 13: //modelFlags
            MODL.Load();
            MODL->MODD.Load();
            MODL->MODD->value13 = *(UINT8 *)FieldValue;
            break;
        case 14: //data DATA ,, Struct
            DATA.Load();
            DATA->value14 = *(UINT32 *)FieldValue;
            break;
        case 15: //data DATA ,, Struct
            DATA.Load();
            DATA->value15 = *(UINT32 *)FieldValue;
            break;
        case 16: //data DATA ,, Struct
            DATA.Load();
            DATA->value16 = *(UINT32 *)FieldValue;
            break;
        case 17: //data DATA ,, Struct
            DATA.Load();
            DATA->value17 = *(UINT32 *)FieldValue;
            break;
        case 18: //data DATA ,, Struct
            DATA.Load();
            DATA->value18 = *(FLOAT32 *)FieldValue;
            break;
        case 19: //data DATA ,, Struct
            DATA.Load();
            DATA->value19 = *(FLOAT32 *)FieldValue;
            break;
        case 20: //data DATA ,, Struct
            DATA.Load();
            DATA->value20 = *(FLOAT32 *)FieldValue;
            break;
        case 21: //data DATA ,, Struct
            DATA.Load();
            DATA->value21 = *(FLOAT32 *)FieldValue;
            break;
        case 22: //data DATA ,, Struct
            DATA.Load();
            DATA->value22 = *(FLOAT32 *)FieldValue;
            break;
        case 23: //data DATA ,, Struct
            DATA.Load();
            DATA->value23 = *(FLOAT32 *)FieldValue;
            break;
        case 24: //mnam Image Space Modifier
            MNAM.Load();
            MNAM->value24 = *(FORMID *)FieldValue;
            return true;
        default:
            break;
        }
    return false;
    }

void CAMSRecord::DeleteField(FIELD_IDENTIFIERS)
    {
    switch(FieldID)
        {
        case 1: //flags1
            SetHeaderFlagMask(0);
            return;
        case 3: //versionControl1
            flagsUnk = 0;
            return;
        case 4: //eid
            EDID.Unload();
            return;
        case 5: //formVersion
            formVersion = 0;
            return;
        case 6: //versionControl2
            versionControl2[0] = 0;
            versionControl2[1] = 0;
            return;
        case 7: //modPath
            if(MODL.IsLoaded())
                MODL->MODL.Unload();
            return;
        case 8: //modb
            if(MODL.IsLoaded())
                MODL->MODB.Unload();
            return;
        case 9: //modt_p
            if(MODL.IsLoaded())
                MODL->MODT.Unload();
            return;
        case 10: //mods Alternate Textures
            if(MODL.IsLoaded())
                MODL->MODS.Unload();
            return;
        case 11: //mods Alternate Textures
            if(MODL.IsLoaded())
                MODL->MODS.Unload();
            return;
        case 12: //mods Alternate Textures
            if(MODL.IsLoaded())
                MODL->MODS.Unload();
            return;
        case 13: //modelFlags
            if(MODL.IsLoaded())
                MODL->MODD.Unload();
            return;
        case 14: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 15: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 16: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 17: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 18: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 19: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 20: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 21: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 22: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 23: //data DATA ,, Struct
            DATA.Unload();
            return;
        case 24: //mnam Image Space Modifier
            MNAM.Unload();
            return;
        default:
            return;
        }
    }
}