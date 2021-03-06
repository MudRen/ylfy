inherit F_CLEAN_UP;
int help();
int get_biaoshi(string biaoshi, object ob, object me,string sx,int n);

int main(object me, string arg)
{
        object ob;
        string sx;
        int n,sxd;
        
        if(!arg || sscanf(arg,"%s %d",sx,n)!=2)
        {
            help();
            return 1;
        }

        if( me != this_player(1) )
                return 0;
        
        ob = me->query_temp("link_ob");
        
        if( !ob )
                return 0;
        
        while( ob && ob->is_character() )
                ob = ob->query_temp("link_ob");
        
        sxd = me->query("xyzx_sys/shuxingdian",1);
        if(n<=0)
                return notify_fail(HIY"点数必须大于零。\n"NOR);
        if(n>sxd)
                return notify_fail(HIY"你的属性点不足"+n+"点，无法进行加点。\n"NOR);
        
        if(sx != "jz" && sx != "mj" && sx != "fy" && sx != "lx")
        {
            return notify_fail(HIY"属性必须是jz,mj,fy,lx中的一种\n"NOR);
        }
        write(HIY"为了安全起见要求验证身份标识,请输入你的身份标识："NOR);
        input_to("get_biaoshi", 1,ob,me,sx,n);
        return 1;
}

int get_biaoshi(string biaoshi, object ob, object me,string sx,int n)
{
        string old_biaoshi;
        
        old_biaoshi = ob->query("biaoshiold");

        write("\n");
        
        if( crypt(biaoshi, old_biaoshi) != old_biaoshi )
        {
                write(HIR"身份标识验证失败！\n"NOR);
                return 0;
        }
        
        switch (sx)
        {
            case "jz":
                printf(HIG"恭喜你！你的精准提升了%s点。\n"NOR,chinese_number(n));
                me->add("xyzx_sys/jingzhun",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "mj":
                printf(HIW"恭喜你！你的敏捷提升了%s点。\n"NOR,chinese_number(n));
                me->add("xyzx_sys/minjie",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "fy":
                printf(HIC"恭喜你！你的反应提升了%s点。\n"NOR,chinese_number(n));
                me->add("xyzx_sys/fanying",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
            case "lx":
                printf(HIC"恭喜你！你的灵性提升了%s点。\n"NOR,chinese_number(n));
                me->add("xyzx_sys/lingxing",n);
                me->add("xyzx_sys/shuxingdian",-n);
                break;
        }
        return 1;
}

int help()
{
        write(@TEXT
指令格式：jiadian <属性> <点数>
属性是jz、mj、fy、lx中的一种。
这个指令可以让你把属性点分配到 [精准、敏捷、反应、灵性] 四项属性上。
[jz]、精准：影响攻击命中率，数值越高击中对手的几率越大；
[mj]、敏捷：影响闪避率，数值越高越不容易被对手击中；
[fy]、反应：影响格挡几率，有效地格挡可以消减对手大部分伤害；
[lx]、灵性：影响对技能绝招的洞悉力，这个值越高技能绝招施用的成功机会就越大；
TEXT
        );
        return 1;
}
