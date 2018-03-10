#include "SocialMgr.h"
#include "Social/Group.h"

#include <Common.h>
#include <boost/make_shared.hpp>
#include "Forwards.h"


template< class T >
Core::Social::SocialMgr< T >::SocialMgr()
      : m_groupCount( 0 ),
        m_lastGroupId( 0 ),
        m_groups{}
{
}

template< class T >
Core::Social::SocialMgr< T >::~SocialMgr()
{
   
}


template< class T >
T Core::Social::SocialMgr< T >::findGroupByInviteIdForPlayer( uint64_t playerId ) const
{
   auto it = m_invites.find( playerId );
   if( it != m_invites.end() )
   {
      return findGroupById( it->second );
   }
   return nullptr;
}
template< class T >
T Core::Social::SocialMgr< T >::findGroupById( uint64_t groupId ) const
{
   auto it = m_groups.find( groupId );
   if( it != m_groups.end() )
   {
      return it->second;
   }
   return nullptr;
}

template< class T >
uint64_t Core::Social::SocialMgr< T >::generateGroupId()
{
   m_lastGroupId++;
   return m_lastGroupId;
}

template< class T >
bool Core::Social::SocialMgr< T >::hasInvite( uint64_t playerId ) const
{
   auto it = m_invites.find( playerId );
   if ( it != m_invites.end() )
   {
      return true;
   }
   return false;
}