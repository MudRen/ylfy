
#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{     
        string msg;
        string str;
        object target,*name;
        int i,cnt;
        
        if(!me->query("party/zhu"))
                        return notify_fail("只有帮会的帮主才能下达追杀令。\n");
        if(!me->query("party/id"))
                        return notify_fail("你目前尚未加入任何帮派组织。\n");  
        if(! arg)       {
                msg=HIR"黑名单\n"NOR;
                msg+="—————————————————————————————————————\n";
                name=users();
                cnt=0;
                for(i=0;i<sizeof(name);i++)     {
                        if(name[i]->query("vendetta/"+me->query("party/id"))) {
                        msg+=sprintf("%-18s%s",name[i]->query("name")+"("+name[i]->query("id")+")",
                        (cnt%4==3? "\n":""));
                        cnt++;
                        }
                }
                if(cnt==0||(cnt%4))     msg+="\n";
                msg+="—————————————————————————————————————\n";
                me->start_more(msg);
                return 1;
        }
        if(sscanf(arg,"-a %s",str)==1)  {
                target=find_player(str);
                if(!target)
                        return notify_fail("你想追杀的玩家不在游戏中。\n");
				if(wizardp(target) && !wizardp(me))
                        return notify_fail("你想追杀的玩家不在游戏中。\n");
                if(target==me)
                        return notify_fail("追杀自己？没问题吧。\n");
                if(target->query("vendetta/"+me->query("party/id")))
                        return notify_fail("此玩家已在黑名单中。\n");
				if (file_name(environment(target)) == "/d/shaolin/bagua")
					return notify_fail("你想追杀的玩家正处于安全地带。\n");
				if (target->query("age") < 18)
					return notify_fail("为了世界更美好，放过小孩子吧.\n");
				if ( me->query_temp("party_zhuisha") > time() )
					return notify_fail("输入指令过于频繁，请稍候10秒再进行该操作。\n");
                target->set("vendetta/"+me->query("party/id"),1);
                target->save();
           if(me->query("party/id")==(string)target->query("party/id"))
                message("chat",
               HIB"【"HIR"江湖追杀令"HIB"】："HIR"「"+me->query("party/name")+"」帮开始追杀叛徒 "+
                target->query("name")+"("+target->query("id")+")。\n"NOR,users());
                else
               message("channel:chat",HIB"【"HIR"江湖追杀令"HIB"】："HIR"「"+me->query("party/name")+"」帮开始追杀 "+target->query("name")+"("+target->query("id")+")。\n"NOR,users());
				me->set_temp("party_zhuisha", time()+10);
                return 1;
        }
        if(sscanf(arg,"-d %s",str)==1)  {
                target=find_player(str);
                if(! target)    return notify_fail("此处没有这么个玩家。\n");
				if(wizardp(target) && !wizardp(me))
                        return notify_fail("你想追杀的玩家不在游戏中。\n");
                if(! target->query("vendetta/"+me->query("party/id")))
                        return notify_fail("此玩家并不在追杀的黑名单中。\n");
				if ( me->query_temp("party_zhuisha") > time() )
					return notify_fail("输入指令过于频繁，请稍候10秒再进行该操作。\n");
                target->delete("vendetta/"+me->query("party/id"));
//              target->remove_all_killer();
                target->save();
                message("channel:chat",
                HIB"【"HIY"江湖赦免令"HIB"】："HIY"「"+me->query("party/name")+"」帮停止追杀 "+target->query("name")+"("+target->query("id")+")。\n"NOR,users());
				me->set_temp("party_zhuisha", time()+10);
                return 1;
        }
        return notify_fail("指令格式：zhuisha [-a][-d]<玩家ID>\n");
}

int help(object me)
{
        write(@HELP
指令格式：zhuisha [-a][-d]<对象ID>
本指令为帮主专用，不加参数显示目前在线被
追杀的玩家。-a 追杀某玩家，-d 取消追杀某
玩家。当被追杀玩家死亡，则自动停止追杀。
HELP
        );
        return 1;
}

