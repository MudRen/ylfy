#include <ansi.h>
#include <liebiao.h>
inherit ITEM;
void setup()
{}
void init()
{
    if(environment(this_object())==this_player())
    {
        add_action("do_shou","shouchong");
        add_action("do_fang","fangchong");
    }
}

void create()
{
               set_name("竹篓", ({"zhu lou" ,"zl"}));
              set_max_encumbrance(30000);
                set("unit", "个");
                set("long", "这是一个小口大肚的竹篓。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(100);
              set("no_sell",1);
                setup();
}

object find_my_chong(object me,string chongid)
{
    object env,*objs;
    int i,sz;
    string tmp;
    if(!objectp(me))
        return 0;
    env=environment(me);
    objs = all_inventory(env);
    sz = sizeof(objs);
    for(i=0;i<sz;i++)
    {
        if(objs[i]->query("race")!="野兽")
            continue;
        tmp=objs[i]->query("id");
        if(tmp!="zhi zhu" && tmp!="wu gong" && 
                tmp!="chan chu" && tmp!="du she" && tmp!="xie zi")
            continue;
        tmp = base_name(objs[i]);
        if(strsrch(tmp,"/d/wudujiao/npc/")!=0)
            continue;
        tmp = objs[i]->query("host_id");
        if(!tmp || tmp != me->query("id"))
            continue;
        if(objs[i]->query("id")==chongid)
            return objs[i];
    }
    return 0;
}
int do_shou(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s in %s", who, what)!=2)
         return notify_fail("命令格式: shouchong <毒虫> in <物品>。\n");
    ob1= present(what,me);
    ob = find_my_chong(me,who);
//    ob = present(who,environment(me));
    if (!ob )
    {
        ob = present(who,environment(me));
        if(ob)
            return notify_fail(ob->query("name")+"连理都不理你！\n");
        else
            return notify_fail("你要收什么？\n");
    }
    if (!ob1 )
         return notify_fail("你要将虫收到那里？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"连理都不理你！\n");
    message_vision("$N打开竹篓，对着"+ob->query("name")+"轻轻吹了一声口哨。\n",me);
    message_vision("只见"+ob->query("name")+"身子逐渐缩小，化做一只几寸长的小虫，钻进了$N的竹篓里。\n",me);
     ob->move(ob1);
     me->set("wudu_chongzi",base_name(ob));
     return 1;
}
int do_fang(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s from %s", who, what)!=2)
         return notify_fail("命令格式: fangchong <毒虫> from <物品>。\n");
    ob1 = present(what,me);
    if (!ob1)
         return notify_fail("你要从那里放毒虫？\n");
    ob = present(who,ob1);
    if (!ob )
         return notify_fail("你要放什么？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"连理都不理你！\n");
    tell_object(me,  "你悄悄打开竹篓，将里面的"+ob->query("name")+"放了出来。\n" );
 
    message_vision("忽然，一只"+ob->query("name")+"不知从什么地方窜了出来。\n",me);
     ob->move(environment(me));
     me->delete("wudu_chongzi");
     return 1;
}
int query_autoload() { return 1; }

varargs int move(mixed dest, int silently)
{
    object zhulou=this_object();
    object from_env,to_env;
    object *objs;
    string tmp;
    int i,sz,ret;
    from_env = environment(zhulou);
    if(objectp(dest) && playerp(dest) && present("zhu lou",dest))
    {
        if(from_env && playerp(from_env))
            tmp = dest->query("name");
        else
            tmp="你";
        return notify_fail(tmp+"身上已经有了一个竹篓。\n");
    }
    ret = ::move(dest,silently);
    to_env=environment(zhulou);
    if(ret==1 && objectp(to_env))
    {
        if(from_env && playerp(from_env) && from_env->query("wudu_chongzi"))
        {
            objs = all_inventory(zhulou);
            sz=sizeof(objs);
            for(i=0;i<sz;i++)
            {
                tmp = objs[i]->query("id");
                if(tmp=="wu gong" || tmp=="du she" ||
                        tmp=="zhi zhu" || tmp=="xie zi" || tmp=="chan chu")
                {
                    if(objs[i]->query("host_id")==from_env->query("id") && 
                            base_name(objs[i])==from_env->query("wudu_chongzi"))
                    {
                        from_env->delete("wudu_chongzi");
                        break;
                    }
                }
            }
        }
        if(to_env && playerp(to_env))
        {
            objs = all_inventory(zhulou);
            sz=sizeof(objs);
            for(i=0;i<sz;i++)
            {
                tmp = objs[i]->query("id");
                if(tmp=="wu gong" || tmp=="du she" ||
                        tmp=="zhi zhu" || tmp=="xie zi" || tmp=="chan chu")
                {
                    if(objs[i]->query("host_id")==to_env->query("id"))
                    {
                        to_env->set("wudu_chongzi",base_name(objs[i]));
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
