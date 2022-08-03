create schema GameAlpha;

create table users
(
    `id`     int auto_increment primary key,
    `name`   varchar(50)                                                not null,
    `level`  int(2) default 1                                           not null,
    `bossNo` int(3) default 1 comment 'current number of bosses killed' not null,
    constraint users_id_uindex
        unique (id)
);

create table items
(
    `id`       int auto_increment primary key,
    `name`     varchar(50)      not null,
    `value`    int(2) default 1 not null,
    `rarityID` tinyint(1)       not null,
    `statID`   tinyint(1)       not null,
    `cost`     int(3) default 1 not null,
    `passive`  varchar(150),
    constraint items_id_uindex
        unique (id)
);

create table user_items
(
    `userID` int auto_increment primary key,
    `itemID` varchar(50) not null,
    constraint user_item_id_uindex
        unique (userID, itemID)
);

create table abilities
(
    `id`       int auto_increment primary key,
    `name`     varchar(50)               not null,
    `damage`   int(3)        default 1   not null comment 'current number of bosses killed',
    `scale`    decimal(2, 1) default 1.0 not null comment 'damage scale with physical or magical',
    `rarityID` tinyint(1)                not null,
    `statID`   tinyint(1)                not null comment 'the type of damage this scales with',
    constraint users_id_uindex
        unique (id)
);

insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Ice Spike', 70, 0.6, 1, 2);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Ice Ball', 90, 0.8, 2, 2);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Fireball', 100, 1.1, 3, 2);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Flamethrower', 150, 1.6, 4, 2);

insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Jab', 70, 0.6, 1, 1);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Side Kick', 90, 0.8, 1, 1);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('Scissor Kick', 100, 1.1, 3, 1);
insert into abilities (name, damage, scale, rarityID, statID)
VALUES ('God Punch', 150, 1.6, 4, 1);

create table user_abilities
(
    `userID`    int auto_increment primary key,
    `abilityID` varchar(50) not null,
    constraint user_ability_id_uindex
        unique (userID, abilityID)
);

create table bosses
(
    `id`    int auto_increment primary key,
    `name`  varchar(50) not null,
    `stats` text        not null,
    constraint bosses_id_uindex
        unique (id)
);

create table rarity_odds
(
    `id`          int auto_increment primary key,
    `probability` decimal(2, 1) default 1.0 comment 'odds of showing in shop 0.1 being almost never, 1 very high. increased by luck' not null,
    `name`        varchar(50)                                                                                                        not null,
    constraint rarity_odds_id_uindex
        unique (id)
);

insert into rarity_odds (`probability`, `name`)
VALUES (0.75, 'Common');
insert into rarity_odds (`probability`, `name`)
VALUES (0.55, 'Uncommon');
insert into rarity_odds (`probability`, `name`)
VALUES (0.35, 'Rare');
insert into rarity_odds (`probability`, `name`)
VALUES (0.15, 'Legendary');

create table stats
(
    `id`   int auto_increment primary key,
    `name` varchar(50) not null,
    constraint stats_id_uindex
        unique (id)
);
insert into stats (name)
VALUES ('Physical');
insert into stats (name)
VALUES ('Magical');
insert into stats (name)
VALUES ('Health');
insert into stats (name)
VALUES ('Defense');
insert into stats (name)
VALUES ('Luck');
