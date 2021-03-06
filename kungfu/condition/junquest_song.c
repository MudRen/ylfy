// junquest_song
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{      
        object room,jiang,bingfu,kaijia;  
        string temp;
        int liangcao,reward;
        mapping jiangjun;

        room=environment(me);
 
        if( duration < 1 ) return 0;
        me->apply_condition("junquest_song", duration - 1); 

        temp=read_file("/quest/quest_jun/song/reward",1,1);
        reward=atoi(temp);
        if( reward > 0 && me->query_temp("jun_quest") )
        {
          write_file("/quest/quest_jun/song/master","",1);
          tell_object(me,
          HIR"恭喜你胜利完成此次出征任务，击败来犯蒙军"
          +chinese_number(reward)+"余次，实乃我朝之栋梁啊！！！\n"NOR);         
          me->set("jun_quest/reward",reward);  
          //me->delete_temp("jun_quest");
          reward=0;
          temp=sprintf("%d",reward);
          write_file("/quest/quest_jun/song/reward",temp,1);
          me->apply_condition("junquest_song", 0);
          return 0;
        }

        if( !me->query_temp("jun_quest") )
        {
         tell_object(me,HIR"怎么搞的身为一军之帅，行事如此欠思量！"
         +"还不快回军中去？？\n"NOR);
         me->set_temp("jun_quest/party","song");
         bingfu=new("/quest/quest_jun/song/obj/bingfu");
         bingfu->set("owner",me->query("id"));
         bingfu->move(me);
         bingfu->check_me(me);
        }                    

        temp=read_file("/quest/quest_jun/song/master",1,1);
        if( temp != me->query("id") )
        {
          tell_object(me,HIR"你已经被蒙古军击败了！！！\n"NOR);
          bingfu=present("bing fu",me);
          if( objectp(bingfu) ) destruct(bingfu);
          kaijia=present("kai jia",me);
          if( objectp(kaijia) ) destruct(kaijia);
          me->delete("jun_quest");
          me->delete_temp("jun_quest");  
          me->apply_condition("junquest_fail", 500);
          me->apply_condition("junquest_song", 0);          
        }

        if( (time()-me->query("jun_quest/last_jiang")) > 300 )
        {
         jiangjun=me->query("jun_quest/jiang");

         temp=read_file("/quest/quest_jun/song/liangcao",1,1);
         liangcao=atoi(temp);
         if( !jiangjun || sizeof(jiangjun) < me->query("degree_jungong")*2 )         
         if( liangcao > 300 && room
             && file_name(room) == "/quest/quest_jun/sying1" )
         {
          me->set("jun_quest/last_jiang",time());
          tell_object(me,
          HIR"新征一批的宋军到了，赶快加紧训练吧！！！\n"NOR); 
          liangcao=liangcao-100;
          temp=sprintf("%d",liangcao);
          write_file("/quest/quest_jun/song/liangcao",temp,1);
          jiang=new("/quest/quest_jun/song/songb");
          jiang->move(room);
          jiang->change_ob();
         }
        }

        if( duration == 2 )  
        {
          tell_object(me,HIR"蒙古大军久攻不下，终于撤军了！！！\n"NOR);
          reward=5;
          temp=sprintf("%d",reward);
          write_file("/quest/quest_jun/song/reward",temp,1); 
        }

        return CND_CONTINUE;      
}

