
// look.c
#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int look_room(object me, object env,int flag);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
varargs mixed classify_object(object obj,int flag);
string getper(object me, object obj);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        HIB "平淡无奇" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "略有小成" NOR,
        HIB "已有小成" NOR,
        HIB "驾轻就熟" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "略有大成" NOR,
        CYN "已有大成" NOR,
        CYN "豁然贯通" NOR,
        CYN "出类拔萃" NOR,
        CYN "无可匹敌" NOR,
        CYN "技冠群雄" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        CYN "傲视群雄" NOR,
        HIC "登峰造极" NOR,
        HIC "所向披靡" NOR,
        HIC "一代宗师" NOR,
        HIC "神功盖世" NOR,
        HIC "举世无双" NOR,
        HIC "惊世骇俗" NOR,
        HIC "震古铄今" NOR,
        HIC "深藏不露" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        HIR "深不可测" NOR,
        BLU "不堪一击" NOR,
});
string *heavy_level_desc= ({
        "极轻",
        "很轻",
        "不重",
        "不轻",
        "较重",
        "很重",
        "极重"
});

string *per_msg_male1 = ({
        CYN "英俊潇洒,风度翩翩。\n" NOR,
        CYN "相貌出众,面目俊朗。\n" NOR,
        CYN "长得伟岸英挺，顾盼之间，神采飞扬。\n" NOR,
        CYN "丰姿英伟，气宇轩昂，确实是人中龙凤。\n" NOR,
});

string *per_msg_male2 = ({
        CYN "英俊潇洒,颇有气质。\n" NOR,
        CYN "相貌出众，面目俊朗。\n" NOR,
        CYN "面貌清奇，丰姿非俗。\n" NOR,
});
string *per_msg_male3 = ({
        CYN "相貌平平，没什么好看的。\n" NOR,
        CYN "相貌凶恶，满脸横肉。\n" NOR,
        CYN "暴睛环眼，嘴脸凶顽。\n" NOR,
        CYN "相貌平平，一般一般。\n" NOR,
});

string *per_msg_male4 = ({
        CYN "一副蔫蔫的样子，有气无力。 \n" NOR,
        CYN "相貌凶狠，阴险狡诈。\n" NOR,
        CYN "长得一副姥姥不疼，舅舅不爱的模样。\n" NOR,
        CYN "长得蔫蔫的，一副无精打采的模样。 \n" NOR, 
        CYN "五短三粗，肥头大耳，大概是猪八戒的本家。 \n" NOR, 
});


string *per_msg_male61 = ({
        CYN "慈眉善目，让人可亲可敬。\n" NOR,
});
string *per_msg_male62 = ({
        CYN "目光呆滞，让人敬而远之。\n" NOR,
});

string *per_msg_female1 = ({
        CYN "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 \n" NOR,
        CYN "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。 \n" NOR,
        CYN "风情万种，楚楚动人，当真是我见犹怜。 \n" NOR,
});

string *per_msg_female2 = ({
        CYN "容色秀丽，风姿绰约。 \n" NOR,
        CYN "秀发如丝，肌肤如雪。 \n" NOR,
        CYN "俏脸生春，妙目含情。 \n" NOR,
        CYN "风情万种，楚楚动人。 \n" NOR,
});

string *per_msg_female3 = ({
        CYN "虽算不上绝世佳人，也颇有几份姿色。 \n" NOR,
        CYN "长得还欠丽质，确颇有几份动人姿色。  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "长得比较难看。 \n" NOR,
        CYN "长得………唉！  \n" NOR,
});

string *per_msg_female61 = ({
        CYN "慈眉善目，让人可亲可敬。\n" NOR,
});
string *per_msg_female62 = ({
        CYN "目光呆滞，让人敬而远之。\n" NOR,
});

string *per_msg_beast1 = ({
        CYN "看起来好可爱哦。 \n" NOR,
        CYN "看起来好招人喜欢。  \n" NOR,
        CYN "胖胖嘟嘟，逗人喜欢。\n" NOR,
});

string *per_msg_beast2 = ({
        CYN "看起来流理流气。 \n" NOR,
        CYN "一副凶巴巴的样子。  \n" NOR,
});

string *per_msg_beast3 = ({
        CYN "看上去有气无力的，象是几天没吃饭的样子。 \n" NOR,
        CYN "一副恶狠狠的样子。  \n" NOR,
});

string *per_msg_beast4 = ({
        CYN "长的极其丑陋，非常吓人的。 \n" NOR,
        CYN "相貌凶恶，满脸横肉，让人一见就惧怕三分。\n" NOR
});

string *per_msg_kid1 = ({
        CYN "月眉星眼，灵气十足。\n" NOR,
        CYN "机灵活泼，神态非凡。\n" NOR,
        CYN "面若秋月，色如晓花。\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "隆额大眼，脸色红润。\n" NOR,
        CYN "胖胖嘟嘟，逗人喜欢。\n" NOR,
        CYN "细皮嫩肉，口齿伶俐。\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "身材矬矮，傻里傻气。\n" NOR,
        CYN "肥肥胖胖，小鼻小眼。\n" NOR,
        CYN "呆头呆脑，笨手笨脚。\n" NOR,
        CYN "蓬头垢脚，脸黄肌瘦。\n" NOR,
        CYN "神如木鸡，面有病色。\n" NOR,
        CYN "五官不整，四肢不洁。\n" NOR,
});

int abs(int x)
{
    if (x>=0) return x;
    else return -x;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

	if( !arg ) result = look_room(me, environment(me),0);
	else if(arg=="me") result=look_living(me, me);
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
    {
        if( obj->is_character() ) result = look_living(me, obj);
        else result = look_item(me, obj);
    }
	else result = look_room_item(me, arg);
    return result;
}

string look_fight(object me,object env,object * inv,mapping exits)
{
    object ot;
    int i,j;
    string str;
    str="";
    if(!me->query("env/olddisplay")) return "";//取消
    //如果玩家身上没有设置olddisplay这个参数,表示对方愿意使用现在的战斗显示.
    //反之,还是返回原来的显示.
    if (me->is_fighting())
    {
        mixed map;
        int mx,my;
        mx=env->get_matrix_x();
        my=env->get_matrix_y();
        map=allocate(mx*my);
        foreach(ot in inv)
        {
            if (ot->query_temp("map"))
            {
                if (ot->query_temp("map/x")<=mx
                &&ot->query_temp("map/x")>=1
                &&ot->query_temp("map/y")<=my
                &&ot->query_temp("map/y")>=1)
               map[ot->query_temp("map/x")-1+(ot->query_temp("map/y")-1)*mx]=ot->query("id");
            }
        }
        for(i=0;i<my;i++)
        {
        for(j=0;j<mx;j++)
        {
            if (map[i*mx+j])
            str+=sprintf(HIY"%|10.8s"NOR,map[i*mx+j]);
            else
            if (mapp(exits) && ( stringp(exits["west"]) && j==0 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["east"]) && j==mx-1 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["north"]) && i==0 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["south"]) && i==my-1 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["southeast"]) && i==my-1 && j==mx-1
              ||stringp(exits["southwest"]) && i==my-1 && j==0
              ||stringp(exits["northeast"]) && i==0 && j==mx-1
              ||stringp(exits["northwest"]) && i==0 && j==0
              ))
                str+=sprintf(HIG"%|10s"NOR,"出口");
            else
            str+=sprintf("%|10s","--");
        }
        str+="\n";
        }
    }
    //printf("\e[256D%s>" NOR, ctime(time())[11..18]);
	
	//return printf("\e[256D""%s",str );
    return str;
}

int look_room(object me, object env,int flag)
{
        int i;
        object *inv;
        mapping buffo = ([]), buffobj = ([]);
        string bfile, name;
        string stt;
        object ot;
        mixed coor;
        mapping exits;
        string str, *dirs;

        if (!userp(me) ) return 1;
        if( !env ) {
                write("你的四周灰蒙蒙地一片，什麽也没有。\n");
                return 1;
        }
//        if(!random(30))
//       "/adm/daemons/room"->add_file(file_name(env));
        name=env->query("outdoors");
        
	if(flag>3) return 1;
	if((!stringp(name)||NATURE_D->check_weather(name)==0)
            &&!env->query_temp("light")
    	    &&!wizardp(me))
        {
    		tell_object(me,"你的四周灰蒙蒙地一片，伸手不见五指。\n"
                                "隐隐约约的看见出口。\n");
    		if( mapp(exits = env->query("exits"))&&(flag<2) ) 
        	{
        		dirs = keys(exits);
        		for(i=0; i<sizeof(dirs); i++)
           			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
               				dirs[i] = 0;
               		dirs -= ({ 0 });
               		if( sizeof(dirs)==0 )
                   		str = "    这里没有任何明显的出路。\n";
               		else if( sizeof(dirs)==1 )
                   		str = "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
               		else
                   		str = sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " +
                                                BOLD + "%s" + NOR + "。\n",
               		implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
         	}

    		if(str)
    			tell_object(me,str);
    		return 1;                           
   	}
	if(!arrayp(coor=env->query("coor"))) coor=({0,0,0});
    	str = sprintf(HIC "%s"NOR" - %s\n%s%s",
    	env->query("short"),
    	wizardp(me)? (file_name(env)+"\t坐标:\t"+(string)coor[0]+"\t"+coor[1]+"\t"+coor[2]): "",
    	(flag>0)?"":env->query("long"),
    	(env->query("outdoors")&&flag<1)? NATURE_D->outdoor_room_description(env) : "" );
    	exits = env->query("exits");
	if( mapp(exits)&&(flag<2) )
    	{
    		dirs = keys(exits);
        	for(i=0; i<sizeof(dirs); i++)
        	if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
             		dirs[i] = 0;
        	dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                	str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                	str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                	str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " +
                       BOLD + "%s" + NOR + "。\n",
                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
    	}

    	inv = all_inventory(env);
	if(flag>2) inv=({});
    	for(i=0; i<sizeof(inv); i++) 
        {
        	if( inv[i]==me ) continue;
        	if( inv[i]->query("no_shown")) continue;
        	if( !me->visible(inv[i]) ) continue;
           	if (userp(inv[i]))
              	{
                        str +="    "+inv[i]->short()+"\n";
              		continue;
              	}
            	bfile=base_name(inv[i])+"-$-"+inv[i]->short();
            	if ( member_array(bfile,keys(buffo)) == -1 )
                {
                	buffo[bfile]=1;
                 	buffobj[bfile]=inv[i];
                }
            	else 
                	buffo[bfile]+=1;
                
        }
        
	for (i=0 ; i <sizeof(keys(buffo)); i ++)
	{
    		stt = keys(buffo)[i];
    		ot = buffobj[stt];
    		if ( !objectp(ot) )  continue;
    		if ( ot ->query("combined_item") != 1 && buffo[stt] > 1 )
        		str+=sprintf("    %s%s",chinese_number(buffo[stt]),!ot->query("unit")?"个":ot->query("unit"))+ot->short()+"\n";
    		else str +="    "+ot->short()+"\n";
	}
    	str+=look_fight(me,env,inv,exits);
   	tell_object(me,str);
   	return 1;
}

int look_item(object me, object obj)
{
        mixed str;
        string prep;

                if(NATURE_D->check_weather()!=1
                        &&!environment(me)->query_temp("light")
                        &&!wizardp(me))
                        {
            tell_object(me,"你的四周灰蒙蒙地一片，伸手不见五指。什么也看不见。\n");
            return 1;                           
                        }
        write(obj->long());
        str = classify_object(obj);
        if( stringp(str) && strlen(str)>1) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "上";
                                break;
                        case "under":
                                prep = "下";
                                break;
                        case "behind":
                                prep = "后";
                                break;
                        case "inside":
                                prep = "里";
                                break;
                        default:
                                prep = "里";
                                break;
                        }
                message("vision", sprintf("%s面有：\n  %s\n", prep,str ), me);
        }
        return 1;
}

string getper(object me, object obj)
{
        int spi,per,age;

        int weight;
        string str,race;

        per = obj->query_per();
        spi = me->query_spi();

// 灵性差的人看的不准
        if (spi>20) weight = 0;
        else weight = (int)(20 - spi)/4 ;

        if (random(10)>6) per = per - weight;
        else per = per + weight ;
    age=(obj->query_temp("apply/age")?
        obj->query_temp("apply/age"):obj->query("age"));
    race=(obj->query_temp("apply/race")?
        obj->query_temp("apply/race"):obj->query("race"));
    if ( race == "人类" )
    {
        if ( obj->query_temp("apply/gender")== "男性" ||
    (obj->query("gender")=="男性"&&!obj->query_temp("apply/gender")))
        {
            if ( age > 60 )
                if ( per > 15 )
                    return ( per_msg_male61[random(sizeof(per_msg_male61))] );
                else
                    return ( per_msg_male62[random(sizeof(per_msg_male62))] );
            if ( age < 16 )
                {
                if(per>=15)
                    return ( per_msg_kid1[random(sizeof(per_msg_kid1))] );
                if(per>=10)
                    return ( per_msg_kid2[random(sizeof(per_msg_kid2))] );
                if(per<10)
                    return ( per_msg_kid3[random(sizeof(per_msg_kid3))] );
                }

            if ( per >= 20 )
                return ( per_msg_male1[random(sizeof(per_msg_male1))] );
            else if ( per >= 15 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))] );
            else if ( per >=10 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))] );
            else
                return ( per_msg_male4[random(sizeof(per_msg_male4))] );
        }
        if ( obj->query_temp("apply/gender")== "女性" ||
    (obj->query("gender")=="女性"&&!obj->query_temp("apply/gender")))
        {
            if ( age > 60 )
                if ( per > 15 )
                    return ( per_msg_female61[random(sizeof(per_msg_female61))] );
                else
                    return ( per_msg_female62[random(sizeof(per_msg_female62))] );
            if ( age < 16 )
                {
                if(per>=15)
                    return ( per_msg_kid1[random(sizeof(per_msg_kid1))] );
                if(per>=10)
                    return ( per_msg_kid2[random(sizeof(per_msg_kid2))] );
                if(per<10)
                    return ( per_msg_kid3[random(sizeof(per_msg_kid3))] );
                }
            if ( per >= 20 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))] );
            else if ( per >= 15 )
                return ( per_msg_female2[random(sizeof(per_msg_female2))] );
            else if ( per >=10 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))] );
            else 
                return ( per_msg_female4[random(sizeof(per_msg_female4))] );
        }
    }
    else if ( race == "野兽" )
    {
        if ( per >= 20 )
            return ( per_msg_beast1[random(sizeof(per_msg_beast1))] );
        else if ( per >= 10 )
            return ( per_msg_beast2[random(sizeof(per_msg_beast2))] );
        else if ( per < 10 )
            return ( per_msg_beast3[random(sizeof(per_msg_beast3))] );
    }
      if( !str) str="";
        return str;
}

string gettof(object me, object ob)
{
        object weapon;
        mapping prepare;
        string skill_type,desc;
        int attack_points,dodge_points,attack_lv,dodge_lv;
        if( objectp(weapon = ob->query_temp("weapon")) )
             skill_type = weapon->query("skill_type");
        else if (prepare&&sizeof(prepare)>0)
             skill_type = (keys(prepare))[0];
        else skill_type = "unarmed";
        attack_points = COMBAT_D->skill_power(ob, skill_type,
SKILL_USAGE_ATTACK);
        if(attack_points<0)attack_points=0;
        if(dodge_points<0 ) dodge_points=0;
        dodge_points  = COMBAT_D->skill_power(ob, "dodge"
,SKILL_USAGE_DEFENSE);
        attack_lv =to_int(sqrt(to_float(attack_points+1)))/8;
        dodge_lv  =to_int(sqrt(to_float(dodge_points+1)))/8;
        if(attack_lv>=sizeof(tough_level_desc))
             attack_lv =sizeof(tough_level_desc)-1;
        if( dodge_lv>=sizeof(tough_level_desc))
             dodge_lv =sizeof(tough_level_desc)-1;
        desc = "攻击功夫好象是"+tough_level_desc[((int)attack_lv)]
             +"。\n防御功夫好象是"+ tough_level_desc[((int)dodge_lv)];
        return  desc;
}

int look_living(object me, object obj)
{
        string str,   pro;
        mixed *inv;
        mapping my_fam, fam;

                if(NATURE_D->check_weather()!=1
                        &&!environment(me)->query_temp("light")
                        &&!wizardp(me))
                        {
            tell_object(me,"你的四周灰蒙蒙地一片，伸手不见五指。什么也看不见。\n");
            return 1;                           
                        }
        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什麽主意。
\n", obj);

        str = obj->long();

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
                str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));
        if(obj->query("MarrY")&&obj->query("MarrY")==me->query("id"))
                {
                if(obj->query("gender")=="女性")
                    str+=sprintf(MAG"她是你的妻子。\n"NOR);
                else 
                    str+=sprintf(MAG"他是你的丈夫。\n"NOR);
                }
    if(obj->is_character()&&!obj->is_corpse()){
                str+=getper(me,obj);
                str+=gettof(me,obj);
                str += sprintf("。\n");
                str +=sprintf("%s的出手似乎",pro);
                str +=getdam(me,obj);
                str += sprintf("。\n");
    }
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "男性" )
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

        if( obj->query("max_kee") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100
/ (int)obj->query("max_kee")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1
);
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带
著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  √" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什麽也没有。\n");

        if(NATURE_D->check_weather()!=1
           &&!env->query_temp("light")
           &&!wizardp(me))
        {
        	tell_object(me,"你的四周灰蒙蒙地一片，伸手不见五指。什么也看不见。\n");
            	return 1;                           
        }
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) 
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) 
        {
                if(objectp(exits[arg]))
                    look_room(me,exits[arg],0);
                 else if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env,0);
                else 
                {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]),0);
                }
                return 1;
        }
        if(wiz_level(me)>2 && env=find_player(arg))
        {
                look_room(me, environment(env),0);
                return 1;
        }

        return notify_fail("你要看什麽？\n");
}
string getdam(object me, object obj)
{

        int level;
        level = obj->query("force")/500+obj->query_str()+
    obj->query_temp("apply/damage")/10;
        level = level / 8;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}
varargs mixed classify_object(object obj,int flag)
{
        object *inv,ot;
        int i;
        string bfile,name,file_name,str,temp;
        mapping buffo=([]),buffobj=([]);
        
        str="";
        inv = all_inventory(obj);
        if( sizeof(inv)<1 )
                return 0;
        for(i=0; i<sizeof(inv); i++) 
        {
                if(inv[i]->query("no_shown")) continue;
                if (inv[i]->query("equipped"))
                {
                        temp = inventory_look(inv[i], flag);
                        if (stringp(temp)) str+=temp+"\n";
                        continue;
                }
                
                if ( flag==1 ) continue;

                bfile=base_name(inv[i])+"--"+inv[i]->short();
                if ( member_array(bfile,keys(buffo)) == -1 )
                {
                        buffo[bfile]=1;
                        buffobj[bfile]=inv[i];
                }
                else 
                {
                        buffo[bfile]+=1;
                }
                
        }
        
        for (i=0 ; i <sizeof(keys(buffo)); i ++)
        {
                sscanf(keys(buffo)[i],"%s--%s",file_name,name);
                ot = buffobj[keys(buffo)[i]];
                if ( !objectp(ot) ) 
                        continue;
                if ( ot ->query("combined_item") != 1 && buffo[keys(buffo)[i]] > 1 )
                        str+=sprintf("    %s%s",chinese_number(buffo[keys(buffo)[i]]),!ot->query("unit")?"个":ot->query("unit"))+ot->short()+"\n";
                else str +="    "+ot->short()+"\n";
        }

        return str;
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。
如果是look me。那么可以看见自己。

HELP
);
        return 1;
}
