/*
 * Copyright (c) since 2021 by PopolonY2k and Leidson Campos A. Ferreira
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <map>
#include "collision/collider.h"
#include "sprite/texturemap.h"


namespace SunLight {
    namespace Sprite  {
        /**
         * @brief Sunlight sprite management class implementation.
         * 
         */
        class Sprite : public SunLight :: Canvas :: Canvas  {

            /**
             * @brief Texture sequence list definition.
             * 
             */
            typedef std :: map<int, TextureMap*>  TextureSequenceList;

            TextureSequenceList             m_Sequences;
            TextureSequenceList :: iterator m_itActiveSequence;
            bool                            m_bIsValidActiveSequence;

            public:

            Sprite( void );
            virtual ~Sprite( void );

            void AddTextureSequence( int nSequence,
                                     SunLight :: Canvas :: TextureCanvas* pTexture,
                                     int64_t nDelayMilli = -1 );
            bool SetActiveTextureSequence( int nSequence );
            int GetActiveTextureSequence( void );
            SunLight :: Canvas :: TextureCanvas* GetActiveTexture( void );

            void SetVisible( bool bVisible );

            void Move( SunLight :: TileMap :: stCoordinate2D& step );

            void Update( void );
            void Unload( void );
        };
    }
}

#endif /* __SPRITE_H__ */
